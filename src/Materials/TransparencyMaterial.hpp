/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef TRANSPARENCYMATERIAL_HPP
#define TRANSPARENCYMATERIAL_HPP

#include "IMaterial.hpp"

namespace RayTracer {
    class TransparencyMaterial : public IMaterial {
    public:
        TransparencyMaterial(const Color &color, float transparency, float refractiveIndex):
        _color(color), _transparency(transparency), _refractiveIndex(refractiveIndex) {}

        Color getColor() const override;

        float getTransparency() const override;

        float getRefractiveIndex() const override;

    private:
        Color _color;
        float _transparency;
        float _refractiveIndex;
    };
}


#endif //TRANSPARENCYMATERIAL_HPP
