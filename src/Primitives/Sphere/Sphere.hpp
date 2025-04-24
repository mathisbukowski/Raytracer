/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere.hpp
*/

#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "../IPrimitive.hpp"
#include "../../Core/Ray.hpp"

namespace RayTracer {
    /**
     * @class Sphere
     * Represents a sphere in 3D space.
     */
    class Sphere : public IPrimitive {
    public:

        /**
         * Constructs a Sphere with a specified center and radius.
         * @param center const Point3D & The center of the sphere.
         * @param radius double The radius of the sphere.
         * @param color Color The color of the sphere.
         */
        Sphere(const Point3D &center, double radius, Color color);

        /**
         * Checks if a ray intersects with the sphere.
         * @param ray const Ray & The ray to check for intersection.
         * @return true if the ray intersects with the sphere, false otherwise.
         */
        bool hits(const Ray &ray) const;

        /**
         * Gets the center of the sphere.
         * @return A constant reference to the center of the sphere.
         */
        const Point3D& getCenter() const { return _center; }
        /**
         * Gets the radius of the sphere.
         * @return The radius of the sphere.
         */
        double getRadius() const { return _radius; }
        /**
         * Gets the color of the sphere.
         * @return A constant reference to the color of the sphere.
         */
        const Color& getColor() const { return _color; }
    private:
        Point3D _center; ///< The center of the sphere.
        double _radius; ///< The radius of the sphere.
        Color _color; ///< The color of the sphere.
    };
}

#endif //RAYTRACER_SPHERE_HPP
