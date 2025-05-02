/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "TransparencyMaterialFactory.hpp"

#include "Materials/TransparencyMaterial.hpp"

/**
    material = {
        type = "transparent";
        color = { r = 150; g = 200; b = 255; };
        transparency = 0.7;
        refractiveIndex = 1.5;
    };
 */
std::shared_ptr<RayTracer::IMaterial> RayTracer::TransparencyMaterialFactory::createMaterial(const libconfig::Setting& setting)
{
    const libconfig::Setting& colorSetting = setting.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");

    float transparency = setting.lookup("transparency");
    float refractiveIndex = setting.lookup("refractiveIndex");

    return std::make_shared<TransparencyMaterial>(Color(r, g, b), transparency, refractiveIndex);
}
