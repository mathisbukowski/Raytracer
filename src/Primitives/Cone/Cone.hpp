/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cone.hpp
*/

#ifndef RAYTRACER_CONE_HPP
#define RAYTRACER_CONE_HPP

#include "../IPrimitive.hpp"
#include "../../Math/Vector3D.hpp"
#include "../../Math/Point3D.hpp"
#include "../../Core/Ray.hpp"
#include "../../Materials/IMaterial.hpp"
#include "../../Utils/Color.hpp"
#include <cmath>

namespace RayTracer {
    /**
     * @class Cone
     * Represents a cone in 3D space.
     */
    class Cone : public IPrimitive {
    public:
        /**
         * Constructs a Cone with a specified apex, axis, base radius and height.
         * @param apex const Point3D & The apex (top point) of the cone.
         * @param axis const Vector3D & The axis vector of the cone (pointing from apex to base).
         * @param baseRadius float The radius of the cone's base.
         * @param height float The height of the cone.
         * @param color Color The color of the cone.
         * @param material const std::shared_ptr<IMaterial> & The material of the cone.
         */
        Cone(const Point3D &apex, const Vector3D &axis, float baseRadius, float height,
             Color color, const std::shared_ptr<IMaterial> &material = nullptr);

        /**
         * Checks if a ray intersects with the cone.
         * @param ray const Ray & The ray to test for intersection.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if the ray intersects the cone, false otherwise.
         */
        bool intersect(const Ray &ray, float &t, Vector3D &normal) const override;

        /**
         * Translates the cone by a given vector.
         * @param translation const Vector3D & The translation vector.
         */
        void translate(const Vector3D &translation) override;

        /**
         * Rotates the cone by a given vector.
         * @param rotation const Vector3D & The rotation vector.
         */
        void rotate(const Vector3D &rotation) override;

        /**
         * Gets the material of the cone.
         * @return A shared pointer to the material of the cone.
         */
        [[nodiscard]] std::shared_ptr<IMaterial> getMaterial() const override;

        /**
         * Sets the material of the cone.
         * @param material const std::shared_ptr\<IMaterial\> & The material to set.
         */
        void setMaterial(const std::shared_ptr<IMaterial> &material) override;

        /**
         * Gets the apex of the cone.
         * @return The apex of the cone.
         */
        const Point3D &getApex() const;

        /**
         * Gets the axis vector of the cone.
         * @return The axis vector of the cone.
         */
        const Vector3D &getAxis() const;

        /**
         * Gets the base radius of the cone.
         * @return The base radius of the cone.
         */
        float getBaseRadius() const;

        /**
         * Gets the height of the cone.
         * @return The height of the cone.
         */
        float getHeight() const;

        /**
         * Gets the color of the cone.
         * @return The color of the cone.
         */
        const Color &getColor() const;

        /**
         * Helper method to get the base center point of the cone.
         * @return The center point of the cone's base.
         */
        Point3D getBaseCenter() const;

        /**
         * Helper method to calculate the half angle of the cone.
         * @return The half angle of the cone in radians.
         */
        float getHalfAngle() const;

    private:
        Point3D _apex; ///< The apex (top point) of the cone.
        Vector3D _axis; ///< The axis vector of the cone (pointing from apex to base).
        float _baseRadius; ///< The radius of the cone's base.
        float _height; ///< The height of the cone.
        Color _color; ///< The color of the cone.
        std::shared_ptr<IMaterial> _material; ///< The material of the cone.


    };
}

#endif //RAYTRACER_CONE_HPP