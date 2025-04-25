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

namespace RayTracer {

Engine::Engine(int width, int height)
    : _width(width),
      _height(height),
      _camera(Vector3D(0, 0, 0), Vector3D(0, 0, 0), 60.0f, width, height)
{}

void Engine::setScene(const Scene& scene) {
    _scene = scene;
    _sceneSet = true;
}

void Engine::setCamera(const Camera& camera) {
    _camera = camera;
    _cameraSet = true;
}

static Ray computeReflectedRay(const Vector3D& origin, const Vector3D& incident, const Vector3D& normal) {
    Vector3D reflectedDir = incident - 2.0f * incident.dot(normal) * normal;
    return Ray(origin + normal * 0.001f, reflectedDir.normalized());
}

Color Engine::computeLighting(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDir)
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

Color Engine::computeReflection(const Ray& ray, const Vector3D& point, const Vector3D& normal, int depth)
{
    Ray reflectedRay = computeReflectedRay(point, ray.getDirection(), normal);
    return traceRay(reflectedRay, depth + 1);
}

Color Engine::traceRay(const Ray& ray, int depth) {
    if (depth > MAX_DEPTH)
        return _scene.getBackgroundColor();

    std::shared_ptr<IPrimitive> closest = nullptr;
    float t = 0;
    Vector3D normal;

    if (!_scene.findNearestIntersection(ray, closest, t, normal))
        return _scene.getBackgroundColor();

    auto material = closest->getMaterial();
    if (!material)
        return _scene.getBackgroundColor();

    Vector3D intersection = ray.pointAt(t);
    Vector3D viewDir = -ray.getDirection();

    Color lighting = computeLighting(intersection, normal, viewDir);
    float reflectivity = material->getReflectivity();

    if (reflectivity > 0.0f) {
        Color reflected = computeReflection(ray, intersection, normal, depth);
        return lighting * (1.0f - reflectivity) + reflected * reflectivity;
    }

    return lighting;
}

void Engine::render(const std::string& outputFile) {
    if (!_cameraSet || !_sceneSet) {
        throw std::runtime_error("Engine error: camera or scene not set before rendering");
    }

    std::vector<Color> framebuffer(_width * _height);

    for (int y = 0; y < _height; ++y) {
        for (int x = 0; x < _width; ++x) {
            Ray ray = _camera.generateRay(x, y);
            Color color = traceRay(ray);
            framebuffer[y * _width + x] = color;
        }
    }
    PPMWriter::write(outputFile, _width, _height, framebuffer);
}

}
