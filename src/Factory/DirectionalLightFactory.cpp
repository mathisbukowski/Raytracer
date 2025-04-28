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
    Vector3D color(1.0f, 1.0f, 1.0f);

    if (setting.exists("direction")) {
        const libconfig::Setting& dirSetting = setting["direction"];
        float x = 0.0f, y = -1.0f, z = 0.0f;
        dirSetting.lookupValue("x", x);
        dirSetting.lookupValue("y", y);
        dirSetting.lookupValue("z", z);
        direction = Vector3D(x, y, z);
    }
    setting.lookupValue("intensity", intensity);
    if (setting.exists("color")) {
        const libconfig::Setting& colorSetting = setting["color"];
        float r = 1.0f, g = 1.0f, b = 1.0f;
        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
        color = Vector3D(r, g, b);
    }
    return std::make_shared<DirectionalLight>(direction, intensity, color);
}