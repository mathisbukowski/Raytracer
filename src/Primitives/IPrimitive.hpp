/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** IPrimitive
*/

#ifndef RAYTRACER_IPRIMITIVE_HPP
#define RAYTRACER_IPRIMITIVE_HPP

#include <memory>
#include "../Math/Vector3D.hpp"
#include "../Core/Ray.hpp"
#include "../Materials/IMaterial.hpp"

namespace RayTracer {

    /**
     * @class IPrimitive
     * Interface for geometric primitives in the ray tracing engine.
     */
    class IPrimitive {
    public:
        /**
         * Virtual destructor for the IPrimitive interface.
         */
        virtual ~IPrimitive() = default;

        /**
         * Checks if a ray intersects with the primitive.
         * @param ray const Ray & The ray to test for intersection.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if the ray intersects the primitive, false otherwise.
         */
        virtual bool intersect(const Ray& ray, float& t, Vector3D& normal) const = 0;

        /**
         * Translates the primitive by a given vector.
         * @param translation const Vector3D & The translation vector.
         */
        virtual void translate(const Vector3D& translation) = 0;

        /**
         * Rotates the primitive by a given vector.
         * @param rotation const Vector3D & The rotation vector.
         */
        virtual void rotate(const Vector3D& rotation) = 0;

        /**
         * Gets the material of the primitive.
         * @return A shared pointer to the material of the primitive.
         */
        virtual std::shared_ptr<IMaterial> getMaterial() const = 0;

        /**
         * Sets the material of the primitive.
         * @param material const std::shared_ptr\<IMaterial\> & The material to set.
         */
        virtual void setMaterial(const std::shared_ptr<IMaterial>& material) = 0;
    };

}

#endif //RAYTRACER_IPRIMITIVE_HPP