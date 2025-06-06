/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "AmbientLightFactory.hpp"

#include "../Lights/AmbientLight.hpp"


std::shared_ptr<RayTracer::ILight> RayTracer::AmbientLightFactory::createLight(const libconfig::Setting& setting) const
{
    float intensity = 0.0f;
    float r = 1.0f, g = 1.0f, b = 1.0f;
    bool canCastShadows = false;

    setting.lookupValue("intensity", intensity);

    if (setting.exists("color")) {
        const libconfig::Setting& colorSetting = setting["color"];
        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
    }
    setting.lookupValue("shadow", canCastShadows);

    return std::make_shared<AmbientLight>(intensity, Color(r, g, b), canCastShadows);
}
