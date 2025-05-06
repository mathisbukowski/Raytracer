/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#ifndef DROPSHADOW_HPP
#define DROPSHADOW_HPP

#include "ILight.hpp"

namespace RayTracer
{
    /**
     * @class DropShadow
     * Class representing a drop shadow light source.
     */
    class DropShadow : public ILight
    {
    public:
        /**
         * Constructor for the DropShadow class.
         * @param position The position of the light source.
         * @param intensity The intensity of the light source.
         * @param color The color of the light source.
         */
        DropShadow(const Vector3D& position, float intensity, const Color& color);

        /**
         * Destructor for the DropShadow class.
         */
        ~DropShadow() override = default;

        /**
         * Calculates the illumination at a given point.
         * @param point The point in space where the illumination is calculated.
         * @param normal The normal vector at the point.
         * @param viewDirection The direction from the point to the viewer.
         * @return The color of the light at the given point.
         */
        Color calculateIllumination(const Point3D& point, const Vector3D& normal, const Vector3D& viewDirection) const override;
        /**
         * Gets the position of the light source.
         * @return The position of the light source.
         */
        Vector3D getPosition() const override;

        /**
         * Gets the intensity of the light source.
         * @return The intensity of the light source.
         */
        float getIntensity() const override;

        /**
         * Gets the color of the light source.
         * @return The color of the light source.
         */
        Vector3D getColor() const override;

        /**
         * Gets the direction of the light at a given point.
         * @param point The point in space where the light direction is calculated.
         * @return The direction of the light at the given point.
         */
        Vector3D getLightDirection(const Point3D& point) const override;
        /**
         * Checks if the light source can cast shadows.
         * @return True if the light can cast shadows, false otherwise.
         */
        bool canCastShadow() const override;
        /**
         * Gets the direction of the light source.
         * @return The direction of the light source.
         */
        Vector3D getDirection() const override;

    private:
        Vector3D _position; ///< Position of the light source
        float _intensity; ///< Intensity of the light source
        Color _color; ///< Color of the light source
        Vector3D _direction; ///< Direction of the light source
        float _shadowIntensity; ///< Intensity of the shadow
        float _shadowSize; ///< Size of the shadow
    };
}



#endif //DROPSHADOW_HPP
