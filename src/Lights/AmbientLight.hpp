/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef AMBIENTLIGHT_HPP
#define AMBIENTLIGHT_HPP


#include "ILight.hpp"

namespace RayTracer {
    class AmbientLight : public ILight {
        float _intensity;
        Vector3D _color;
    public:
        explicit AmbientLight(float intensity = 0.4f, const Vector3D& color = Vector3D(1.0f, 1.0f, 1.0f))
            : _intensity(intensity), _color(color) {}

        Vector3D getPosition() const override;
        float getIntensity() const override;
        Vector3D getColor() const override;
        bool isAmbient() const override;

        Color calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const override;

        Vector3D getLightDirection(const Point3D& point) const override;

        bool canCastShadow() const override;
    };
}


#endif //AMBIENTLIGHT_HPP
