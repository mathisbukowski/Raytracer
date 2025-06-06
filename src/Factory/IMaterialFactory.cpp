/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "IMaterialFactory.hpp"

#include <unordered_map>

#include "FlatColorMaterialFactory.hpp"
#include "TransparencyMaterialFactory.hpp"

std::shared_ptr<RayTracer::IMaterialFactory> RayTracer::IMaterialFactory::getFactory(const std::string& type)
{
    static std::unordered_map<std::string, std::shared_ptr<IMaterialFactory>> factoryMap = {
        {"flat", std::make_shared<FlatColorMaterialFactory>()},
        {"transparent", std::make_shared<TransparencyMaterialFactory>()},
    };

    auto it = factoryMap.find(type);
    if (it == factoryMap.end())
        return nullptr;
    return it->second;
}
