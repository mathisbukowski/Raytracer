/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PrimitiveFactory.hpp"

#include <unordered_map>

std::shared_ptr<RayTracer::IPrimitiveFactory> RayTracer::IPrimitiveFactory::getFactory(const std::string& type)
{
    static std::unordered_map<std::string, std::shared_ptr<IPrimitiveFactory>> factories = {
        {"sphere", std::make_shared<SphereFactory>()},
        {"plane", std::make_shared<PlaneFactory>()},
        {"cylinder", std::make_shared<CylinderFactory>()},
        {"cone", std::make_shared<ConeFactory>()},
    };

    auto it = factories.find(type);
    if (it == factories.end())
        return nullptr;
    return it->second;
}
