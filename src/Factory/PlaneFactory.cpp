/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PlaneFactory.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::PlaneFactory::createPrimitive(const libconfig::Setting& settings)
{
    std::string axis = settings.lookup("axis").c_str();
    double position = settings.lookup("position");

    const libconfig::Setting& colorSetting = settings.lookup("color");
    int r = colorSetting.lookup("r");
    int g = colorSetting.lookup("g");
    int b = colorSetting.lookup("b");

    return std::make_shared<Plane>(axis, position, Color(r, g, b));
}
