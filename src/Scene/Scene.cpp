/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#include "Scene.hpp"

#include <limits>

namespace RayTracer {

    Scene::Scene()
        : _backgroundColor(0, 0, 0)
    {}

    void Scene::addLight(const std::shared_ptr<ILight>& light)
    {
        _lights.push_back(light);
    }

    void Scene::addPrimitive(const std::shared_ptr<IPrimitive>& primitive)
    {
        _primitives.push_back(primitive);
    }

    bool Scene::findNearestIntersection(const Ray& ray, std::shared_ptr<IPrimitive>& hitPrimitive, float& t, Vector3D& normal) const
    {
        bool found = false;
        float closestT = std::numeric_limits<float>::max();
        Vector3D closestNormal;

        for (const auto& primitive : _primitives) {
            float localT;
            Vector3D localNormal;
            if (primitive->intersect(ray, localT, localNormal)) {
                if (localT < closestT) {
                    closestT = localT;
                    closestNormal = localNormal;
                    hitPrimitive = primitive;
                    found = true;
                }
            }
        }

        if (found) {
            t = closestT;
            normal = closestNormal;
        }

        return found;
    }

    const Color& Scene::getBackgroundColor() const
    {
        return _backgroundColor;
    }

    const std::vector<std::shared_ptr<ILight>>& Scene::getLights() const
    {
        return _lights;
    }

    const std::vector<std::shared_ptr<IPrimitive>>& Scene::getPrimitives() const
    {
        return _primitives;
    }

    void Scene::setBackgroundColor(const Color& color)
    {
        _backgroundColor = color;
    }
}
