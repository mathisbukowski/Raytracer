/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cylinder.hpp
*/

#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#include "../IPrimitive.hpp"
#include "../../Math/Vector3D.hpp"
#include "../../Math/Point3D.hpp"
#include "../../Core/Ray.hpp"
#include "../../Materials/IMaterial.hpp"
#include "../../Utils/Color.hpp"
#include <cmath>

namespace RayTracer {
    /**
     * @class Cylinder
     * Represents a cylinder in 3D space.
     */
    class Cylinder : public IPrimitive {
    public:
        /**
         * Constructs a Cylinder with a specified base point, axis, radius and height.
         * @param base const Point3D & The base point of the cylinder.
         * @param axis const Vector3D & The axis vector of the cylinder.
         * @param radius float The radius of the cylinder.
         * @param height float The height of the cylinder.
         * @param color Color The color of the cylinder.
         * @param material const std::shared_ptr<IMaterial> & The material of the cylinder.
         */
        Cylinder(const Point3D &base, const Vector3D &axis, float radius, float height,
                 Color color, const std::shared_ptr<IMaterial> &material = nullptr);

        /**
         * Checks if a ray intersects with the cylinder.
         * @param ray const Ray & The ray to test for intersection.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if the ray intersects the cylinder, false otherwise.
         */
        bool intersect(const Ray &ray, float &t, Vector3D &normal) const override;

        /**
         * Translates the cylinder by a given vector.
         * @param translation const Vector3D & The translation vector.
         */
        void translate(const Vector3D &translation) override;

        /**
         * Rotates the cylinder by a given vector.
         * @param rotation const Vector3D & The rotation vector.
         */
        void rotate(const Vector3D &rotation) override;

        /**
         * Gets the material of the cylinder.
         * @return A shared pointer to the material of the cylinder.
         */
        [[nodiscard]] std::shared_ptr<IMaterial> getMaterial() const override;

        /**
         * Sets the material of the cylinder.
         * @param material const std::shared_ptr\<IMaterial\> & The material to set.
         */
        void setMaterial(const std::shared_ptr<IMaterial> &material) override;

        /**
         * Gets the base point of the cylinder.
         * @return The base point of the cylinder.
         */
        const Point3D &getBase() const;

        /**
         * Gets the axis vector of the cylinder.
         * @return The axis vector of the cylinder.
         */
        const Vector3D &getAxis() const;

        /**
         * Gets the radius of the cylinder.
         * @return The radius of the cylinder.
         */
        float getRadius() const;

        /**
         * Gets the height of the cylinder.
         * @return The height of the cylinder.
         */
        float getHeight() const;

        /**
         * Gets the color of the cylinder.
         * @return The color of the cylinder.
         */
        const Color &getColor() const;

    private:
        Point3D _base; ///< The base point of the cylinder.
        Vector3D _axis; ///< The axis vector of the cylinder.
        float _radius; ///< The radius of the cylinder.
        float _height; ///< The height of the cylinder.
        Color _color; ///< The color of the cylinder.
        std::shared_ptr<IMaterial> _material; ///< The material of the cylinder.
    };
}


#endif //RAYTRACER_CYLINDER_HPP