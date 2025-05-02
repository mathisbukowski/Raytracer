/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "../Utils/Color.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {

    /**
     * @class IMaterial
     * Interface for material properties in the ray tracing engine.
     */
    class IMaterial {
    public:
        /**
         * Virtual destructor for the IMaterial interface.
         */
        virtual ~IMaterial() = default;

        /**
         * Gets the color of the material at a given intersection point.
         * @return The color of the material at the intersection point.
         */
        virtual Color getColor() const = 0;

        /**
         * Gets the reflectivity of the material.
         * @return The reflectivity value (default is 0.0f).
         */
        virtual float getReflectivity() const { return 0.0f; }

        /**
         * Gets the transparency of the material.
         * @return The transparency value (default is 0.0f).
         */
        virtual float getTransparency() const { return 0.0f; }

        /**
         * Gets the refractive index of the material.
         * @return The refractive index value (default is 1.0f).
         */
        virtual float getRefractiveIndex() const { return 1.0f; }
    };

}

#endif /* !IMATERIAL_HPP_ */