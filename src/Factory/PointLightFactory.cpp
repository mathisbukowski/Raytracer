/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PointLightFactory.hpp"


std::shared_ptr<RayTracer::ILight> RayTracer::PointLightFactory::createLight(const libconfig::Setting& setting) const
{
    Vector3D position(0, 0, 0);
    float intensity = 0.0f;
    float r = 1.0f, g = 1.0f, b = 1.0f;
    bool canCastShadow = false;

    setting.lookupValue("position.x", position.x);
    setting.lookupValue("position.y", position.y);
    setting.lookupValue("position.z", position.z);
    setting.lookupValue("intensity", intensity);

    if (setting.exists("color")) {
        const libconfig::Setting& colorSetting = setting["color"];
        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
    }
    setting.lookupValue("shadow", canCastShadow);

    Color color(r, g, b);
    return std::make_shared<PointLight>(position, intensity, color, canCastShadow);
}
