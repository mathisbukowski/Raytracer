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
    /**
     * @class FlatColorMaterial
     * Represents a flat color material.
     */
    class FlatColorMaterial : public IMaterial {
    public:
        /**
         * Constructor for FlatColorMaterial.
         * @param color The color of the material.
         * @param transparency The transparency of the material (default is 0.0f).
         */
        FlatColorMaterial(const Color& color, float transparency = 0.0f):
        _color(color), _transparency(transparency) {}

        /**
         * Destructor for FlatColorMaterial.
         */
        ~FlatColorMaterial() override = default;
        /**
         * Gets the color of the material.
         * @return The color of the material.
         */
        Color getColor() const override;
        /**
         * Gets the reflectivity of the material.
         * @return The reflectivity value (default is 0.0f).
         */
        float getTransparency() const override;

    private:
        Color _color; ///< The color of the material
        float _transparency; ///< The transparency of the material
    };
}


#endif //FLATCOLORMATERIAL_HPP
