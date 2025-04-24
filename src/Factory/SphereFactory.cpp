/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "SphereFactory.hpp"


std::shared_ptr<RayTracer::IPrimitive> RayTracer::SphereFactory::createPrimitive(const libconfig::Setting& settings)
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");
    double radius = settings.lookup("r");

    const libconfig::Setting& colorSetting = settings.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");

    return std::make_shared<RayTracer::Sphere>(Vector3D(x, y, z), radius, Color(r, g, b));
}
