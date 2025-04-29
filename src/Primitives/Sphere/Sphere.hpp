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
#include "../../Materials/IMaterial.hpp"

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
         * Gets the center of the sphere.
         * @return A constant reference to the center of the sphere.
         */
        [[nodiscard]] const Point3D& getCenter() const;
        /**
         * Gets the radius of the sphere.
         * @return The radius of the sphere.
         */
        [[nodiscard]] double getRadius() const;
        /**
         * Gets the color of the sphere.
         * @return A constant reference to the color of the sphere.
         */
        [[nodiscard]] const Color& getColor() const;

        /**
         * Checks if a ray intersects with the primitive.
         * @param ray const Ray & The ray to test for intersection.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if the ray intersects the primitive, false otherwise.
         */
        bool intersect(const Ray& ray, float& t, Vector3D& normal) const override;
        /**
         * Translates the primitive by a given vector.
         * @param translation const Vector3D & The translation vector.
         */
        void translate(const Vector3D& translation) override;

        /**
         * Rotates the primitive by a given vector.
         * @param rotation const Vector3D & The rotation vector.
         */
        void rotate(const Vector3D& rotation) override;

        /**
         * Gets the material of the primitive.
         * @return A shared pointer to the material of the primitive.
         */
        std::shared_ptr<IMaterial> getMaterial() const override;

        /**
         * Sets the material of the primitive.
         * @param material const std::shared_ptr\<IMaterial\> & The material to set.
         */
        void setMaterial(const std::shared_ptr<IMaterial>& material) override;
    private:
        Point3D _center; ///< The center of the sphere.
        double _radius; ///< The radius of the sphere.
        Color _color; ///< The color of the sphere.
        Material _material; ///< The material of the sphere.
    };
}

#endif //RAYTRACER_SPHERE_HPP
