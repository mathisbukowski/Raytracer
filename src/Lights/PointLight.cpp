/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PointLight.hpp"


namespace RayTracer {
    PointLight::PointLight(const Vector3D& position, float intensity, const Color& color, const bool& canCastShadow)
    : _position(position), _intensity(intensity), _color(color), _canCastShadow(canCastShadow) {}

    Color PointLight::calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D&) const {
        Vector3D lightDir = this->getLightDirection(point);
        float diffuseFactor = std::max(0.0f, normal.dot(lightDir));
        return _color * _intensity * diffuseFactor;
    }

    bool PointLight::canCastShadow() const
    {
        return _canCastShadow;
    }

    Color PointLight::getColor() const
    {
        return _color;
    }

    float PointLight::getIntensity() const
    {
        return _intensity;
    }

    Vector3D PointLight::getLightDirection(const Point3D& point) const
    {
        Vector3D direction = this->getPosition() - Vector3D(point.x, point.y, point.z);
        return direction.normalized();
    }

    Vector3D PointLight::getPosition() const
    {
        return _position;
    }

    Vector3D PointLight::getDirection() const
    {
        return Vector3D(0, 0, 0);
    }

}
