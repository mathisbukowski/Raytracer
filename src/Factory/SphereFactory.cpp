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
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");
    double radius = settings.lookup("radius");

    const libconfig::Setting& colorSetting = settings.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");
    std::shared_ptr<IMaterial> material = nullptr;
    if (settings.exists("material")) {
        const libconfig::Setting& materialSetting = settings.lookup("material");
        std::string materialType = materialSetting.lookup("type");
        auto factory = IMaterialFactory::getFactory(materialType);
        material = factory->createMaterial(materialSetting);
    }

    return std::make_shared<Sphere>(Point3D(x, y, z), radius, Color(r, g, b), material);
}
