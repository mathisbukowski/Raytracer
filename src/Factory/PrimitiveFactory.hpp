/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
#define PRIMITIVEFACTORY_HPP_

#include <memory>
#include <string>
#include "../Primitives/IPrimitive.hpp"
#include "../Utils/Color.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {

    /**
     * @class PrimitiveFactory
     * Factory class for creating primitive objects.
     */
    class PrimitiveFactory {
    public:
        /**
         * Creates a sphere primitive.
         * @param center const Vector3D & The center of the sphere.
         * @param radius float The radius of the sphere.
         * @param color const Color & The color of the sphere.
         * @return A shared pointer to the created sphere primitive.
         */
        static std::shared_ptr<IPrimitive> createSphere(const Vector3D& center, float radius, const Color& color);

        /**
         * Creates a plane primitive.
         * @param normal const Vector3D & The normal vector of the plane.
         * @param distance float The distance of the plane from the origin.
         * @param color const Color & The color of the plane.
         * @return A shared pointer to the created plane primitive.
         */
        static std::shared_ptr<IPrimitive> createPlane(const Vector3D& normal, float distance, const Color& color);

        /**
         * Creates a cylinder primitive.
         * @param base const Vector3D & The base point of the cylinder.
         * @param axis const Vector3D & The axis vector of the cylinder.
         * @param radius float The radius of the cylinder.
         * @param color const Color & The color of the cylinder.
         * @return A shared pointer to the created cylinder primitive.
         */
        static std::shared_ptr<IPrimitive> createCylinder(const Vector3D& base, const Vector3D& axis, float radius, const Color& color);

        /**
         * Creates a cone primitive.
         * @param apex const Vector3D & The apex point of the cone.
         * @param axis const Vector3D & The axis vector of the cone.
         * @param angle float The angle of the cone.
         * @param color const Color & The color of the cone.
         * @return A shared pointer to the created cone primitive.
         */
        static std::shared_ptr<IPrimitive> createCone(const Vector3D& apex, const Vector3D& axis, float angle, const Color& color);
    };

}

#endif // PRIMITIVEFACTORY_HPP_
