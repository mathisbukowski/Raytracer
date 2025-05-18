/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Engine
*/

#include "Engine.hpp"
#include "../Utils/PPMWriter.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <thread>

namespace RayTracer {

Engine::Engine(int width, int height)
    : _camera(Camera(Point3D(0, 0, 0), Vector3D(0, 0, 0), 60.0f, width, height)),
      _width(width),
      _height(height)
{}

void Engine::setScene(const Scene& scene) {
    _scene = scene;
    _sceneSet = true;
}

void Engine::setCamera(const Camera& camera) {
    _camera = camera;
    _cameraSet = true;
}

Ray Engine::computeReflectedRay(const Point3D& origin, const Vector3D& incident, const Vector3D& normal) {
    Vector3D reflectedDir = incident - 2.0f * incident.dot(normal) * normal;
    return Ray(origin + normal * 0.001f, reflectedDir.normalized());
}

Color Engine::computeLighting(const Point3D& point, const Vector3D& normal, const Vector3D& viewDir)
{
    Color lighting(0, 0, 0);

    for (const auto& light : _scene.getLights()) {
        Vector3D lightDir = light->getLightDirection(point).normalized();

        Ray shadowRay(point + normal * 0.001f, lightDir);
        std::shared_ptr<IPrimitive> shadowHit;
        float shadowT;
        Vector3D shadowNormal;

        bool inShadow = _scene.findNearestIntersection(shadowRay, shadowHit, shadowT, shadowNormal);

        if (!light->canCastShadow() || !inShadow) {
            lighting += light->calculateIllumination(point, normal, viewDir);
        }
    }

    return lighting;
}

Color Engine::computeReflection(const Ray& ray, const Point3D& point, const Vector3D& normal, int depth)
{
    Ray reflectedRay = this->computeReflectedRay(point, ray.getDirection(), normal);
    return this->traceRay(reflectedRay, depth + 1);
}

Ray Engine::computeRefractedRay(const Ray& ray, const Point3D& point, const Vector3D& normal, float refractiveIndex) {
    Vector3D incident = ray.getDirection();
    float cosi = std::clamp(incident.dot(normal), -1.0f, 1.0f);
    float etai = 1.0f;
    float etat = refractiveIndex;
    Vector3D n = normal;

    if (cosi < 0) {
        cosi = -cosi;
    } else {
        std::swap(etai, etat);
        n = -normal;
    }
    float eta = etai / etat;
    float k = 1.0f - eta * eta * (1.0f - cosi * cosi);
    if (k < 0.0f) {
        Vector3D reflectedDir = incident - 2.0f * incident.dot(normal) * normal;
        return Ray(point + normal * 0.001f, reflectedDir.normalized());
    } else {
        Vector3D refractDir = eta * incident + (eta * cosi - std::sqrt(k)) * n;
        return Ray(point - n * 0.001f, refractDir.normalized());
    }
}

float Engine::computeFresnelReflectance(const Vector3D& incident, const Vector3D& normal, float refractiveIndex) {
    float cosi = std::clamp(incident.dot(normal), -1.0f, 1.0f);
    float etai = 1.0f, etat = refractiveIndex;

    if (cosi > 0) {
        std::swap(etai, etat);
    }
    float sint = etai / etat * std::sqrt(std::max(0.0f, 1.0f - cosi * cosi));
    if (sint >= 1.0f) {
        return 1.0f;
    }
    float cost = std::sqrt(std::max(0.0f, 1.0f - sint * sint));
    cosi = std::abs(cosi);
    float Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
    float Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
    return (Rs * Rs + Rp * Rp) / 2.0f;
}

    void Engine::buildPhotonMap(float radius, int maxPhotons)
    {
        if (!_sceneSet) {
            throw std::runtime_error("Cannot build photon map: scene not set.");
        }
        _photonMapping->build(_scene.getLights(), _scene.getPrimitives(), _scene);
        _photonMapping->setGatherRadius(radius);
        _photonMapping->setMaxPhotons(maxPhotons);
    }

Color Engine::traceRay(const Ray& ray, int depth) {
    if (depth > MAX_DEPTH)
        return _scene.getBackgroundColor();

    std::shared_ptr<IPrimitive> closest = nullptr;
    float t = 0;
    Vector3D normal;

    if (!_scene.findNearestIntersection(ray, closest, t, normal))
        return _scene.getBackgroundColor();

    if (!closest) {
        std::cerr << "[ERROR] Closest primitive is nullptr\n";
        return _scene.getBackgroundColor();
    }

    auto material = closest->getMaterial();
    if (!material) {
        std::cerr << "[ERROR] Material is nullptr\n";
        return _scene.getBackgroundColor();
    }

    Point3D intersection = ray.pointAt(t);
    Vector3D viewDir = -ray.getDirection();

    Color materialColor = material->getColor();
    float reflectivity = material->getReflectivity();
    float transparency = material->getTransparency();
    float refractiveIndex = 1.5f;

    if (transparency >= 0.99f && materialColor.r <= 0.01f && materialColor.g <= 0.01f && materialColor.b <= 0.01f) {
        materialColor = Color(0.01f, 0.01f, 0.01f);
    }
    Color lighting = this->computeLighting(intersection, normal, viewDir);
    Color finalColor = Color(
            materialColor.r * lighting.r,
            materialColor.g * lighting.g,
            materialColor.b * lighting.b
    );

    if ((reflectivity > 0.0f || transparency > 0.0f) && depth < MAX_DEPTH) {
        float kr = reflectivity;

        if (transparency > 0.0f) {
            kr = computeFresnelReflectance(ray.getDirection(), normal, refractiveIndex);

            Ray refractedRay = computeRefractedRay(ray, intersection, normal, refractiveIndex);
            Color refractedColor = traceRay(refractedRay, depth + 1);
            finalColor = finalColor * (1.0f - transparency * (1.0f - kr)) +
                         refractedColor * transparency * (1.0f - kr);
        }
        if (kr > 0.0f) {
            Ray reflectedRay = computeReflectedRay(intersection, ray.getDirection(), normal);
            Color reflectedColor = traceRay(reflectedRay, depth + 1);
            float reflectAmount = kr * (reflectivity > 0.0f ? reflectivity : transparency);
            finalColor = finalColor * (1.0f - reflectAmount) + reflectedColor * reflectAmount;
        }
    }

    if (_photonMapping->isEnabled()) {
        Color gi = _photonMapping->estimateRadiance(intersection, normal, _photonMapping->getGatherRadius(), _photonMapping->getMaxPhotons());
        finalColor += gi;
    }

    return finalColor;
}

void Engine::renderBlock(std::vector<Color>& framebuffer, int startY, int endY) {
    for (int y = startY; y < endY; ++y) {
        for (int x = 0; x < _width; ++x) {
            Ray ray = _camera.generateRay(x, y);
            Color color = this->traceRay(ray);
            framebuffer[y * _width + x] = color;
        }
    }
}

void Engine::render(const std::string& outputFile) {
    if (!_cameraSet || !_sceneSet) {
        throw std::runtime_error("Engine error: camera or scene not set before rendering");
    }

    std::vector<Color> framebuffer(_width * _height);

    if (!_enableMultithreading) {
        for (int y = 0; y < _height; ++y) {
            for (int x = 0; x < _width; ++x) {
                Ray ray = _camera.generateRay(x, y);
                Color color = this->traceRay(ray);
                framebuffer[y * _width + x] = color;
            }
        }
        std::cout << std::endl;
    } else {
        unsigned int numThreads = _threadCount;
        if (numThreads == 0) {
            numThreads = std::thread::hardware_concurrency();
            numThreads = std::max(2u, numThreads);
        }
        std::vector<std::thread> threads;

        int linesPerThread = _height / numThreads;
        int remainingLines = _height % numThreads;

        int startY = 0;
        for (unsigned int i = 0; i < numThreads; ++i) {
            int threadLines = linesPerThread + (i < static_cast<unsigned int>(remainingLines) ? 1 : 0);
            int endY = startY + threadLines;
            threads.emplace_back(&Engine::renderBlock, this, std::ref(framebuffer), startY, endY);
            startY = endY;
        }
        for (auto& thread : threads) {
            thread.join();
        }
    }
    PPMWriter::write(outputFile, _width, _height, framebuffer);
}

}
