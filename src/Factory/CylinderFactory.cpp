/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "CylinderFactory.hpp"

#include "IMaterialFactory.hpp"
#include "Primitives/Cylinder/Cylinder.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::CylinderFactory::createPrimitive(const libconfig::Setting& settings)
{
    const libconfig::Setting& baseSetting = settings.lookup("base");
    double x = baseSetting.lookup("x");
    double y = baseSetting.lookup("y");
    double z = baseSetting.lookup("z");

    const libconfig::Setting& axisSetting = settings.lookup("axis");
    double ax = axisSetting.lookup("x");
    double ay = axisSetting.lookup("y");
    double az = axisSetting.lookup("z");

    double radius = settings.lookup("radius");

    const libconfig::Setting& colorSetting = settings.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");

    float height = settings.lookup("height");

    std::shared_ptr<IMaterial> material = nullptr;
    if (settings.exists("material")) {
        const libconfig::Setting& materialSetting = settings.lookup("material");
        std::string materialType = materialSetting.lookup("type");
        auto factory = IMaterialFactory::getFactory(materialType);
        material = factory->createMaterial(materialSetting);
    }


    return std::make_shared<Cylinder>(Point3D(x, y, z), Vector3D(ax, ay, az), radius, height, Color(r, g, b), material);
}
