/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Ray
*/

#ifndef Ray_HPP_
#define Ray_HPP_

#include "../Math/Vector3D.hpp"
#include "../Math/Point3D.hpp"

namespace RayTracer {

    /**
     * @class Ray
     * Represents a ray in 3D space.
     */
    class Ray {
    private:
        Point3D _origin; ///< The origin point of the ray.
        Vector3D _direction; ///< The direction vector of the ray.

    public:
        /**
         * Constructs a Ray with a specified origin and direction.
         * @param origin const Vector3D & The origin point of the ray.
         * @param direction const Vector3D & The direction vector of the ray.
         */
        Ray(const Point3D& origin, const Vector3D& direction);

        /**
         * Gets the origin point of the ray.
         * @return A constant reference to the origin point.
         */
        const Point3D& getOrigin() const;

        /**
         * Gets the direction vector of the ray.
         * @return A constant reference to the direction vector.
         */
        const Vector3D& getDirection() const;

        /**
         * Computes a point along the ray at a given parameter t.
         * @param t float The parameter along the ray.
         * @return The computed point as a Vector3D.
         */
        Point3D pointAt(float t) const;
    };

}

#endif //Ray_HPP_
