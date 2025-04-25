/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PointLightFactory.hpp"


std::shared_ptr<RayTracer::ILight> RayTracer::PointLightFactory::createLight(const libconfig::Setting& setting) const
{
    Vector3D position = Vector3D(0, 0, 0);
    Vector3D color = Vector3D(0, 0, 0);
    float intensity = 0.0f;

    setting.lookupValue("position.x", position.x);
    setting.lookupValue("position.y", position.y);
    setting.lookupValue("position.z", position.z);
    setting.lookupValue("intensity", intensity);

    if (setting.exists("color")) {
        const libconfig::Setting& colorSetting = setting["color"];
        colorSetting.lookupValue("r", color.x);
        colorSetting.lookupValue("g", color.y);
        colorSetting.lookupValue("b", color.z);
    }

    return std::make_shared<PointLight>(position, intensity, color);
}