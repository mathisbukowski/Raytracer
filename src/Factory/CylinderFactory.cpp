/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "CylinderFactory.hpp"

#include "IMaterialFactory.hpp"


std::shared_ptr<RayTracer::IPrimitive> RayTracer::CylinderFactory::createPrimitive(const libconfig::Setting& settings)
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");

    const libconfig::Setting& axisSetting = settings.lookup("axis");
    double ax = axisSetting.lookup("x");
    double ay = axisSetting.lookup("y");
    double az = axisSetting.lookup("z");

    double radius = settings.lookup("radius");

    const libconfig::Setting& colorSetting = settings.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");

    std::shared_ptr<IMaterial> material = nullptr;
    std::shared_ptr<const libconfig::Setting> materialSetting = settings.exists("material") ? std::make_shared<libconfig::Setting>(settings.lookup("material")) : nullptr;
    if (materialSetting != nullptr) {
        std::string materialType = materialSetting->lookup("type");
        auto factory = IMaterialFactory::getFactory(materialType);
        material = factory->createMaterial(materialSetting.operator*());
    }

    return std::make_shared<Cylinder>(Vector3D(x, y, z), Vector3D(ax, ay, az), radius, Color(r, g, b), material);
}
