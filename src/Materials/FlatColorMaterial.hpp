/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef FLATCOLORMATERIAL_HPP
#define FLATCOLORMATERIAL_HPP

#include "IMaterial.hpp"

namespace RayTracer {
    class FlatColorMaterial : public IMaterial {
    public:
        FlatColorMaterial(const Color& color, float transparency = 0.0f):
        _color(color), _transparency(transparency) {}

        Color getColor() const override;

        float getTransparency() const override;

    private:
        Color _color;
        float _transparency;
    };
}


#endif //FLATCOLORMATERIAL_HPP
