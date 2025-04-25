/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "DirectionalLight.hpp"


namespace RayTracer {
    Color DirectionalLight::calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const
    {
        float diffuseFactor = normal.dot(-this->getDirection());

        Vector3D colorVector = this->getColor() * this->getIntensity() * diffuseFactor;
        return Color(colorVector.x, colorVector.y, colorVector.z);
    }

    bool DirectionalLight::canCastShadow() const
    {
        return true;
    }

    Vector3D DirectionalLight::getColor() const
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

    Vector3D DirectionalLight::getLightDirection(const Point3D& point) const
    {
        return  -(this->getDirection());
    }

    Vector3D DirectionalLight::getPosition() const
    {
        return Vector3D(0, 0, 0);
    }

    bool DirectionalLight::isDirectional() const
    {
        return true;
    }



}