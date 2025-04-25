/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "AmbientLightFactory.hpp"

#include "../Lights/AmbientLight.hpp"


std::shared_ptr<RayTracer::ILight> RayTracer::AmbientLightFactory::createLight(const libconfig::Setting& setting) const
{
    return nullptr;
}

