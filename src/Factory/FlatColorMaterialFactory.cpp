/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "FlatColorMaterialFactory.hpp"

#include "Materials/FlatColorMaterial.hpp"

/**
    material = {
    type = "flat";
    color = { r = 255; g = 100; b = 50; };
    transparency = 0.2;
    };
*/
std::shared_ptr<RayTracer::IMaterial> RayTracer::FlatColorMaterialFactory::createMaterial(const libconfig::Setting& setting)
{
    const libconfig::Setting& colorSetting = setting.lookup("color");

    float r = colorSetting.lookup("r");
    float g = colorSetting.lookup("g");
    float b = colorSetting.lookup("b");

    float transparency = 0.0f;
    setting.lookupValue("transparency", transparency);

    return std::make_shared<FlatColorMaterial>(
        Color(r, g, b),
        transparency
    );
}
