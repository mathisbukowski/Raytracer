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
    /**
     * @class AmbientLight
     * Represents an ambient light source in the scene.
     */
    class AmbientLight : public ILight {
    public:
        /**
         * Constructor for AmbientLight.
         * @param intensity The intensity of the ambient light (default is 0.4).
         * @param color The color of the ambient light (default is white).
         */
        AmbientLight(float intensity, const Color& color);

        /**
         * Gets the position of the ambient light.
         * @return The position of the ambient light (always returns (0, 0, 0) for ambient light).
         */
        Vector3D getPosition() const override;
        /**
         * Gets the intensity of the ambient light.
         * @return The intensity of the ambient light.
         */
        float getIntensity() const override;
        /**
         * Gets the color of the ambient light.
         * @return The color of the ambient light.
         */
        Color getColor() const override;
        /**
         * Calculates the illumination at a given point.
         * @param point The point in space where the illumination is calculated.
         * @param normal The normal vector at the point.
         * @param viewDirection The direction from the point to the viewer.
         * @return The color of the light at the given point.
         */
        Color calculateIllumination([[maybe_unused]] const Point3D& point, [[maybe_unused]] const Vector3D& normal, [[maybe_unused]] const Vector3D& viewDirection) const override;
        /**
         * Gets the light direction at a given point.
         * @param point The point in space where the light direction is calculated.
         * @return The direction of the light at the given point (always returns (0, 0, 0) for ambient light).
         */
        Vector3D getLightDirection([[maybe_unused]] const Point3D& point) const override;
        /**
         * Checks if the light can cast shadows.
         * @return True if the light can cast shadows, false otherwise.
         */
        bool canCastShadow() const override;
        /**
         * Gets the direction
         * @return The direction of the Light
         */
        Vector3D getDirection() const override;
    private:
        float _intensity; ///< Intensity of the ambient light
        Color _color; ///< Color of the ambient light
    };
}


#endif //AMBIENTLIGHT_HPP
