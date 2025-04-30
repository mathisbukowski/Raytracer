/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "TransparencyMaterial.hpp"

RayTracer::Color RayTracer::TransparencyMaterial::getColor() const
{
    return _color;
}

float RayTracer::TransparencyMaterial::getRefractiveIndex() const
{
    return _refractiveIndex;
}

float RayTracer::TransparencyMaterial::getTransparency() const
{
    return _transparency;
}

