/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef DIRECTIONALLIGHT_HPP
#define DIRECTIONALLIGHT_HPP

#include "ILight.hpp"

namespace RayTracer {
    class DirectionalLight : public ILight {
        Vector3D _direction;
        float _intensity;
        Vector3D _color;

    public:
        DirectionalLight(
        const Vector3D& direction = Vector3D(0, -1, 0),
        float intensity = 0.6f,
        const Vector3D& color = Vector3D(1.0f, 1.0f, 1.0f))
            : _direction(direction), _intensity(intensity), _color(color)
        {
            _direction = direction.normalized();
        }

        Vector3D getPosition() const override;
        float getIntensity() const override;
        Vector3D getColor() const override;
        Vector3D getDirection() const override;
        bool isDirectional() const override;

        Color calculateIllumination(const Point3D& point, const Vector3D& normal,
                                   const Vector3D& viewDirection) const override;

        Vector3D getLightDirection(const Point3D& point) const override;

        bool canCastShadow() const override;
    };
}



#endif //DIRECTIONALLIGHT_HPP
