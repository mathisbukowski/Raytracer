/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "SphereFactory.hpp"

#include "IMaterialFactory.hpp"
#include "Primitives/Sphere/Sphere.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::SphereFactory::createPrimitive(const libconfig::Setting& settings)
{
    const libconfig::Setting& center = settings.lookup("center");

    double x = center.lookup("x");
    double y = center.lookup("y");
    double z = center.lookup("z");
    double radius = settings.lookup("radius");

    Color color(1.0f, 1.0f, 1.0f);
    std::shared_ptr<IMaterial> material = nullptr;

    if (settings.exists("material")) {
        const libconfig::Setting& materialSetting = settings.lookup("material");
        std::string materialType = materialSetting.lookup("type");

        Color matColor(1.0f, 1.0f, 1.0f);
        if (materialSetting.exists("color")) {
            const libconfig::Setting& colorSetting = materialSetting.lookup("color");
            double r = 1.0, g = 1.0, b = 1.0;
            colorSetting.lookupValue("r", r);
            colorSetting.lookupValue("g", g);
            colorSetting.lookupValue("b", b);
            matColor = Color(static_cast<float>(r), static_cast<float>(g), static_cast<float>(b));
        }

        auto factory = IMaterialFactory::getFactory(materialType);
        material = factory->createMaterial(materialSetting);
        color = matColor;
    }
    return std::make_shared<Sphere>(Point3D(x, y, z), radius, color, material);
}
