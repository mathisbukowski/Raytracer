/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "ILight.hpp"


namespace RayTracer {
    class PointLight : public ILight {
    public:
        PointLight(const Vector3D& position = Vector3D(0, 0, 0),
                   float intensity = 0.8f,
                   const Vector3D& color = Vector3D(1.0f, 1.0f, 1.0f))
            : _position(position), _intensity(intensity), _color(color) {}

        Vector3D getPosition() const override;
        float getIntensity() const override;
        Vector3D getColor() const override;
        bool isPoint() const override;
        Color calculateIllumination(const Point3D& point, const Vector3D& normal,
                                   const Vector3D& viewDirection) const override;

        Vector3D getLightDirection(const Point3D& point) const override;

        bool canCastShadow() const override;
    private:
        Vector3D _position;
        float _intensity;
        Vector3D _color;
    };
}

#endif //POINTLIGHT_HPP
