/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#include "Scene.hpp"

namespace RayTracer {
    void Scene::addLight(const std::shared_ptr<ILight>& light)
    {
        (void)light;
        return;
    }

    void Scene::addPrimitive(const std::shared_ptr<IPrimitive>& primitive)
    {
        (void)primitive;
        return;
    }

    bool Scene::findNearestIntersection(const Ray& ray, std::shared_ptr<IPrimitive>& hitPrimitive, float& t, Vector3D& normal) const
    {
        (void)ray;
        (void)hitPrimitive;
        (void)t;
        (void)normal;
        return true;
    }

    const Color& Scene::getBackgroundColor() const
    {
        static const Color dummyColor(0, 0, 0);  // Valeur statique pour éviter le return-local-addr
        return dummyColor;
    }

    const std::vector<std::shared_ptr<ILight>>& Scene::getLights() const
    {
        static const std::vector<std::shared_ptr<ILight>> dummyLights;
        return dummyLights;
    }

    const std::vector<std::shared_ptr<IPrimitive>>& Scene::getPrimitives() const
    {
        static const std::vector<std::shared_ptr<IPrimitive>> dummyPrimitives;
        return dummyPrimitives;
    }

    void Scene::setBackgroundColor(const Color& color)
    {
        (void)color;  // Ignore l'argument
    }
    Scene::Scene()
    {
        _backgroundColor = Color(0, 0, 0);
        _lights = std::vector<std::shared_ptr<ILight>>();
        _primitives = std::vector<std::shared_ptr<IPrimitive>>();
    }

}