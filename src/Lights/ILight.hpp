/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** ILight
*/

#ifndef RAYTRACER_ILIGHT_HPP_
#define RAYTRACER_ILIGHT_HPP_

#include "../Math/Vector3D.hpp"
#include "../Math/Point3D.hpp"
#include "../Utils/Color.hpp"

namespace RayTracer {

    /**
     * @class ILight
     * Interface for light sources in the ray tracing engine.
     */
    class ILight {
    public:
        /**
         * Virtual destructor for the ILight interface.
         */
        virtual ~ILight() = default;

        /**
         * Calculates the illumination at a given point.
         * @param point const Vector3D & The point where illumination is calculated.
         * @param normal const Vector3D & The normal vector at the point.
         * @param viewDirection const Vector3D & The direction of the viewer.
         * @return The calculated color of the illumination.
         */
        virtual Color calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const = 0;

        /**
         * Gets the direction of the light at a given point.
         * @param point const Vector3D & The point where the light direction is calculated.
         * @return The direction vector of the light.
         */
        virtual Vector3D getLightDirection(const Point3D& point) const = 0;

        /**
         * Checks if the light source can cast shadows.
         * @return True if the light can cast shadows, false otherwise.
         */
        virtual bool canCastShadow() const = 0;
        /**
         * Gets the position of the light source.
         * @return The position vector of the light source.
         */
        virtual Vector3D getPosition() const = 0;
        /**
         * Gets the intensity of the light source.
         * @return The intensity of the light source.
         */
        virtual float getIntensity() const = 0;
        /**
         * Gets the color of the light source.
         * @return The color vector of the light source.
         */
        virtual Vector3D getColor() const = 0;
        /**
         * Checks if the light source is a spotlight.
         * @return True if the light is a spotlight, false otherwise.
         */
        virtual Vector3D getDirection() const = 0;
    };
}

#endif //RAYTRACER_ILIGHT_HPP_
