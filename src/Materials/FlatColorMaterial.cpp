/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "FlatColorMaterial.hpp"

RayTracer::Color RayTracer::FlatColorMaterial::getColor() const
{
    return _color;
}

float RayTracer::FlatColorMaterial::getTransparency() const
{
    return _transparency;
}

