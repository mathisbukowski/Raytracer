/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "AmbientLightFactory.hpp"
#include "PointLightFactory.hpp"
#include "DirectionalLightFactory.hpp"
#include "ILightFactory.hpp"
#include <unordered_map>

std::shared_ptr<RayTracer::ILightFactory> RayTracer::ILightFactory::getFactory(const std::string& type)
{
    static std::unordered_map<std::string, std::shared_ptr<ILightFactory>> factories = {
        {"ambient", std::make_shared<AmbientLightFactory>()},
        {"directional", std::make_shared<DirectionalLightFactory>()},
        {"point", std::make_shared<PointLightFactory>()},
    };

    auto it = factories.find(type);
    if (it != factories.end())
        return it->second;
    return nullptr;
}
