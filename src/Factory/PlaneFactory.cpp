/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PlaneFactory.hpp"

#include "IMaterialFactory.hpp"
#include "Primitives/Plane/Plane.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::PlaneFactory::createPrimitive(const libconfig::Setting& settings)
{
    std::string normal = settings.lookup("axis").c_str();
    double position = settings.lookup("position");

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

    return std::make_shared<Plane>(normal, position, Color(r, g, b), material);
}
