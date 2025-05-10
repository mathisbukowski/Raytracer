/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "DirectionalLightFactory.hpp"


std::shared_ptr<RayTracer::ILight> RayTracer::DirectionalLightFactory::createLight(const libconfig::Setting& setting) const
{
    Vector3D direction(0, -1, 0);
    float intensity = 0.6f;
    float r = 1.0f, g = 1.0f, b = 1.0f;
    bool canCastShadow = true;

    if (setting.exists("direction")) {
        const libconfig::Setting& dirSetting = setting["direction"];
        dirSetting.lookupValue("x", direction.x);
        dirSetting.lookupValue("y", direction.y);
        dirSetting.lookupValue("z", direction.z);
    }

    setting.lookupValue("intensity", intensity);
    if (setting.exists("color")) {
        const libconfig::Setting& colorSetting = setting["color"];
        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
    }
    setting.lookupValue("shadow", canCastShadow);
    return std::make_shared<DirectionalLight>(direction, intensity, Color(r, g, b), canCastShadow);
}
