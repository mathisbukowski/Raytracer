/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "AmbientLight.hpp"

namespace RayTracer {
    Color AmbientLight::calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const
    {
        Vector3D colorVector = this->getColor() * this->getIntensity();
        return Color(colorVector.x, colorVector.y, colorVector.z);
    }

    bool AmbientLight::canCastShadow() const
    {
        return false;
    }

    Vector3D AmbientLight::getColor() const
    {
        return _color;
    }

    float AmbientLight::getIntensity() const
    {
        return _intensity;
    }

    Vector3D AmbientLight::getLightDirection(const Point3D& point) const
    {
        return Vector3D(0, 0, 0);
    }

    Vector3D AmbientLight::getPosition() const
    {
        return Vector3D(0, 0, 0);
    }

    bool AmbientLight::isAmbient() const
    {
        return true;
    }
}