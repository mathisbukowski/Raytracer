/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef DIRECTIONALLIGHT_HPP
#define DIRECTIONALLIGHT_HPP

#include "ILight.hpp"

namespace RayTracer {
    /**
     * @class DirectionalLight
     * Represents a directional light source in the scene.
     */
    class DirectionalLight : public ILight {
    public:
        /**
         * Constructor for DirectionalLight.
         * @param direction The direction of the light (default is (0, -1, 0)).
         * @param intensity The intensity of the light (default is 0.6).
         * @param color The color of the light (default is white).
         */
         DirectionalLight(const Vector3D& direction, float intensity, const Color& color, const bool& canCastShadow);

        /**
         * Gets the position of the directional light.
         * @return The position of the directional light (always returns (0, 0, 0) for directional light).
         */
        Vector3D getPosition() const override;
        /**
         * Gets the intensity of the directional light.
         * @return The intensity of the directional light.
         */
        float getIntensity() const override;
        /**
         * Gets the color of the directional light.
         * @return The color of the directional light.
         */
        Color getColor() const override;
        /**
         * Checks if the light is directional.
         * @return True if the light is directional, false otherwise.
         */
        Vector3D getDirection() const override;
        /**
         * Calculates the illumination at a given point.
         * @param point The point in space where the illumination is calculated.
         * @param normal The normal vector at the point.
         * @param viewDirection The direction from the point to the viewer.
         * @return The color of the light at the given point.
         */
        Color calculateIllumination([[maybe_unused]] const Point3D& point, const Vector3D& normal, [[maybe_unused]] const Vector3D& viewDirection) const override;
        /**
         * Gets the light direction at a given point.
         * @param point The point in space where the light direction is calculated.
         * @return The direction of the light at the given point.
         */
        Vector3D getLightDirection([[maybe_unused]] const Point3D& point) const override;
        /**
         * Checks if the light can cast shadows.
         * @return True if the light can cast shadows, false otherwise.
         */
        bool canCastShadow() const override;
    private:
        Vector3D _direction; ///< Direction of the light
        float _intensity; ///< Intensity of the light
        Color _color; ///< Color of the light
        bool _canCastShadow; ///< Can Cast Shadow bool
    };
}



#endif //DIRECTIONALLIGHT_HPP
