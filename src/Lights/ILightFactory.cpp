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
#include "SceneParser/SceneParser.hpp"

std::shared_ptr<RayTracer::ILightFactory> RayTracer::ILightFactory::getFactory(const std::string& type)
{
    if (type == "ambient")
        return std::make_shared<AmbientLightFactory>();
    if (type == "directional")
        return std::make_shared<DirectionalLightFactory>();
    if (type == "point")
        return std::make_shared<PointLightFactory>();
    throw SceneParser::SceneParserError("Unknown light type: " + type);
}
