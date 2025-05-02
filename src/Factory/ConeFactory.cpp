/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "ConeFactory.hpp"

#include "IMaterialFactory.hpp"
#include "Primitives/Cone/Cone.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::ConeFactory::createPrimitive(const libconfig::Setting& settings)
{
    const libconfig::Setting& apexSetting = settings.lookup("apex");
    double apexX = apexSetting.lookup("x");
    double apexY = apexSetting.lookup("y");
    double apexZ = apexSetting.lookup("z");

    const libconfig::Setting& axisSetting =  settings.lookup("axis");
    double axisX = axisSetting.lookup("x");
    double axisY = axisSetting.lookup("y");
    double axisZ = axisSetting.lookup("z");

    double baseRadius = settings.lookup("baseRadius");
    double height = settings.lookup("height");

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


    return std::make_shared<Cone>(Point3D(apexX, apexY, apexZ), Vector3D(axisX, axisY, axisZ), baseRadius, height, Color(r, g, b), material);
}
