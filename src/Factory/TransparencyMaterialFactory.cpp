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

     double r = colorSetting.lookup("r");
     double g = colorSetting.lookup("g");
     double b = colorSetting.lookup("b");

     float transparency = 0.0f;
     float refractiveIndex = 1.0f;

     setting.lookupValue("transparency", transparency);
     setting.lookupValue("refractiveIndex", refractiveIndex);

     return std::make_shared<TransparencyMaterial>(
         Color(static_cast<float>(r), static_cast<float>(g), static_cast<float>(b)),
         transparency,
         refractiveIndex
     );
 }
