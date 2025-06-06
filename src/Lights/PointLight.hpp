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
    /**
     * @class PointLight
     * Represents a point light source in the scene.
     */
    class PointLight : public ILight {
    public:
        /**
         * Constructor for PointLight.
         * @param position The position of the light (default is (0, 0, 0)).
         * @param intensity The intensity of the light (default is 0.8).
         * @param color The color of the light (default is white).
         * @param canCastShadow  If the light can have a shadow
         */
         PointLight(const Vector3D& position, float intensity, const Color& color, const bool& canCastShadow);

        /**
         * Gets the position of the point light.
         * @return The position of the point light.
         */
        Vector3D getPosition() const override;
        /**
         * Gets the intensity of the point light.
         * @return The intensity of the point light.
         */
        float getIntensity() const override;
        /**
         * Gets the color of the point light.
         * @return The color of the point light.
         */
        Color getColor() const override;
        /**
         * Calculates the illumination at a given point.
         * @param point The point in space where the illumination is calculated.
         * @param normal The normal vector at the point.
         * @param viewDirection The direction from the point to the viewer.
         * @return The color of the light at the given point.
         */
        Color calculateIllumination(const Point3D& point, const Vector3D& normal, [[maybe_unused]] const Vector3D& viewDirection) const override;
        /**
         * Gets the light direction at a given point.
         * @param point The point in space where the light direction is calculated.
         * @return The direction of the light at the given point.
         */
        Vector3D getLightDirection(const Point3D& point) const override;
        /**
         * Checks if the light can cast shadows.
         * @return True if the light can cast shadows, false otherwise.
         */
        bool canCastShadow() const override;
        /**
         * Gets direction
         */
        Vector3D getDirection() const override;
    private:
        Vector3D _position; ///< Position of the point light
        float _intensity; ///< Intensity of the point light
        Color _color; ///< Color of the point light
        bool _canCastShadow; ///< Can Cast Shadow bool
    };
}

#endif //POINTLIGHT_HPP
