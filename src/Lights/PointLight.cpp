/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PointLight.hpp"


namespace RayTracer {
    Color PointLight::calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const
    {
        Vector3D lightDirection = getLightDirection(point);
        float diffuseFactor =  std::max(0.0f, normal.dot(lightDirection));

        Vector3D colorVector = this->getColor() * this->getIntensity() * diffuseFactor;
        return Color(colorVector.x, colorVector.y, colorVector.z);
    }

    bool PointLight::canCastShadow() const
    {
        return true;
    }

    Vector3D PointLight::getColor() const
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

    bool PointLight::isPoint() const
    {
        return true;
    }
}