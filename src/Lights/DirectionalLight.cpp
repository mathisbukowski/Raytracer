/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "DirectionalLight.hpp"


namespace RayTracer {
    DirectionalLight::DirectionalLight(const Vector3D& direction, float intensity, const Color& color, const bool& canCastShadow)
    : _direction(direction.normalized()), _intensity(intensity), _color(color), _canCastShadow(canCastShadow) {}

    Color DirectionalLight::calculateIllumination(const Point3D&, const Vector3D& normal, const Vector3D&) const {
        float diffuseFactor = normal.dot(-_direction);
        return _color * _intensity * std::max(0.0f, diffuseFactor);
    }

    bool DirectionalLight::canCastShadow() const
    {
        return _canCastShadow;
    }

    Color DirectionalLight::getColor() const
    {
        return _color;
    }

    Vector3D DirectionalLight::getDirection() const
    {
        return _direction;
    }

    float DirectionalLight::getIntensity() const
    {
        return _intensity;
    }

    Vector3D DirectionalLight::getLightDirection([[maybe_unused]] const Point3D& point) const
    {
        return  -(this->getDirection());
    }

    Vector3D DirectionalLight::getPosition() const
    {
        return Vector3D(0, 0, 0);
    }
}
