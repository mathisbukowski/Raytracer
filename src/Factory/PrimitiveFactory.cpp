/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PrimitiveFactory.hpp"

#include <unordered_map>
#include "SphereFactory.hpp"
#include "PlaneFactory.hpp"
#include "CylinderFactory.hpp"
#include "ConeFactory.hpp"

std::shared_ptr<RayTracer::IPrimitiveFactory> RayTracer::IPrimitiveFactory::getFactory(const std::string& type)
{
    static std::unordered_map<std::string, std::shared_ptr<IPrimitiveFactory>> factories = {
        {"spheres", std::make_shared<SphereFactory>()},
        {"planes", std::make_shared<PlaneFactory>()},
        {"cylinders", std::make_shared<CylinderFactory>()},
        {"cones", std::make_shared<ConeFactory>()},
    };

    auto it = factories.find(type);
    if (it == factories.end())
        return nullptr;
    return it->second;
}
