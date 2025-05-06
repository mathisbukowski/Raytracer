/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "AmbientLight.hpp"

namespace RayTracer {

    AmbientLight::AmbientLight(float intensity, const Color& color)
        : _intensity(intensity), _color(color) {}

    Color AmbientLight::calculateIllumination(
        [[maybe_unused]] const Point3D& point,
        [[maybe_unused]] const Vector3D& normal,
        [[maybe_unused]] const Vector3D& viewDirection) const
    {
        return _color * _intensity;
    }

    bool AmbientLight::canCastShadow() const
    {
        return false;
    }

    Color AmbientLight::getColor() const
    {
        return _color;
    }

    float AmbientLight::getIntensity() const
    {
        return _intensity;
    }

    Vector3D AmbientLight::getLightDirection(const Point3D& point) const
    {
        (void)point;
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

    Vector3D AmbientLight::getDirection() const
    {
        return Vector3D(0, 0, 0);
    }

}
