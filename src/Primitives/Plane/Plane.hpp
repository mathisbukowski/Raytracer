/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane.hpp
*/

#ifndef RAYTRACER_PLANE_HPP
    #define RAYTRACER_PLANE_HPP

#include "../IPrimitive.hpp"
#include "../../Math/Vector3D.hpp"
#include "../../Math/Point3D.hpp"
#include "../../Core/Ray.hpp"
#include "../../Materials/IMaterial.hpp"
#include "../../Utils/Color.hpp"
#include <memory>
#include <cmath>
#include <string>

namespace RayTracer {
    /**
     * @class Plane
     * Represents a plane in 3D space.
     */
    class Plane : public IPrimitive {
    public:
        /**
         * Constructs a Plane with a specified axis and position.
         * @param axis std::string The axis perpendicular to the plane ("X", "Y", or "Z").
         * @param position float The position of the plane along the axis.
         * @param color const Color & The color of the plane.
         * @param material const std::shared_ptr<IMaterial> & The material of the plane (optional).
         */
        Plane(const Vector3D& normal, const Point3D& point, const std::shared_ptr<IMaterial>& material);
        /**
         * Checks if a ray intersects with the plane.
         * @param ray const Ray & The ray to test for intersection.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if the ray intersects the plane, false otherwise.
         */
        bool intersect(const Ray &ray, float &t, Vector3D &normal) const override;

        /**
         * Translates the plane by a given vector.
         * @param translation const Vector3D & The translation vector.
         */
        void translate(const Vector3D &translation) override;

        /**
         * Rotates the plane by a given vector.
         * @param rotation const Vector3D & The rotation vector.
         */
        void rotate(const Vector3D &rotation) override;

        /**
         * Gets the material of the plane.
         * @return A shared pointer to the material of the plane.
         */
        [[nodiscard]] std::shared_ptr<IMaterial> getMaterial() const override;

        /**
         * Sets the material of the plane.
         * @param material const std::shared_ptr\<IMaterial\> & The material to set.
         */
        void setMaterial(const std::shared_ptr<IMaterial> &material) override;

        /**
         * Gets the point on the plane.
         * @return The point on the plane.
         */
        const Point3D &getPoint() const;

        /**
         * Gets the distance from the origin to the plane.
         * @return The distance from the origin to the plane.
         */
        float getDistance() const;

        /**
         * Gets the normal vector of the plane.
         * @return The normal vector of the plane.
         */
        const Vector3D &getNormal() const;

        /**
         * Gets the color of the plane.
         * @return The color of the plane.
         */
        const Color &getColor() const;

        /**
         * Gets the axis of the plane.
         * @return The axis of the plane.
         */
        const std::string &getAxis() const;

        /**
         * Gets the position of the plane along its axis.
         * @return The position along the axis.
         */
        float getPosition() const;

    private:
        Point3D _point; ///< A point on the plane.
        Vector3D _normal; ///< The normal vector of the plane.
        float _distance; ///< The distance from the origin to the plane.
        std::string _axis; ///< The axis perpendicular to the plane ("X", "Y", or "Z").
        float _position; ///< The position along the axis.
        Color _color; ///< The color of the plane.
        std::shared_ptr<IMaterial> _material; ///< The material of the plane.
    };
}


#endif //RAYTRACER_PLANE_HPP
