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
     Color color(1.0f, 1.0f, 1.0f);
     float transparency = 0.0f;
     float refractiveIndex = 1.0f;

     if (setting.exists("color")) {
         const libconfig::Setting& colorSetting = setting.lookup("color");
         float r = 1.0f, g = 1.0f, b = 1.0f;
         colorSetting.lookupValue("r", r);
         colorSetting.lookupValue("g", g);
         colorSetting.lookupValue("b", b);
         color = Color(r, g, b);
     }

     setting.lookupValue("transparency", transparency);
     setting.lookupValue("refractiveIndex", refractiveIndex);

     return std::make_shared<TransparencyMaterial>(color, transparency, refractiveIndex);
 }
