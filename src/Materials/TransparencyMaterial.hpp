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
    /**
     * @class TransparencyMaterial
     * Represents a transparency material with a color, transparency level, and refractive index.
     */
    class TransparencyMaterial : public IMaterial {
    public:
        /**
         * Constructor for TransparencyMaterial.
         * @param color The color of the material.
         * @param transparency The transparency of the material (default is 0.0f).
         * @param refractiveIndex The refractive index of the material (default is 1.0f).
         */
        TransparencyMaterial(const Color &color, float transparency, float refractiveIndex):
        _color(color), _transparency(transparency), _refractiveIndex(refractiveIndex) {}
        /**
         * Destructor for TransparencyMaterial.
         */
        ~TransparencyMaterial() override = default;
        /**
         * Gets the color of the material.
         * @return The color of the material.
         */
        Color getColor() const override;
        /**
         * Gets the transparency of the material.
         * @return The transparency value (default is 0.0f).
         */
        float getTransparency() const override;
        /**
         * Gets the reflectivity of the material.
         * @return The reflectivity value (default is 0.0f).
         */
        float getRefractiveIndex() const override;

    private:
        Color _color; ///< The color of the material
        float _transparency; ///< The transparency of the material
        float _refractiveIndex; ///< The refractive index of the material
    };
}


#endif //TRANSPARENCYMATERIAL_HPP
