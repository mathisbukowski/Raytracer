/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

namespace RayTracer {

    /**
     * @class Vector3D
     * Represents a 3D vector with basic vector operations.
     */
    class Vector3D {
    public:
        float x, y, z; ///< The x, y, and z components of the vector.

        /**
         * Default constructor for Vector3D.
         * Initializes the vector to (0, 0, 0).
         */
        Vector3D();

        /**
         * Constructs a Vector3D with specified x, y, and z components.
         * @param x float The x component.
         * @param y float The y component.
         * @param z float The z component.
         */
        Vector3D(float x, float y, float z);

        /**
         * Adds two vectors.
         * @param other const Vector3D & The vector to add.
         * @return The resulting vector after addition.
         */
        Vector3D operator+(const Vector3D& other) const;

        /**
         * Subtracts one vector from another.
         * @param other const Vector3D & The vector to subtract.
         * @return The resulting vector after subtraction.
         */
        Vector3D operator-(const Vector3D& other) const;

        Vector3D operator-() const;

        /**
         * Multiplies the vector by a scalar.
         * @param scalar float The scalar value.
         * @return The resulting vector after multiplication.
         */
        Vector3D operator*(float scalar) const;

        /**
         * Divides the vector by a scalar.
         * @param scalar float The scalar value.
         * @return The resulting vector after division.
         */
        Vector3D operator/(float scalar) const;

        /**
         * Computes the dot product of two vectors.
         * @param other const Vector3D & The other vector.
         * @return The dot product as a float.
         */
        float dot(const Vector3D& other) const;

        /**
         * Computes the cross product of two vectors.
         * @param other const Vector3D & The other vector.
         * @return The resulting vector after the cross product.
         */
        Vector3D cross(const Vector3D& other) const;

        /**
         * Computes the length (magnitude) of the vector.
         * @return The length of the vector as a float.
         */
        float length() const;

        /**
         * Normalizes the vector to have a length of 1.
         * @return The normalized vector.
         */
        Vector3D normalized() const;
    };

    Vector3D eulerRotation(const Vector3D& v, const Vector3D& rotation);

    /**
     * Multiplies a scalar by a vector.
     * @param scalar float The scalar value.
     * @param v const Vector3D & The vector.
     * @return The resulting vector after multiplication.
     */
    Vector3D operator*(float scalar, const Vector3D& v);
}

#endif // VECTOR3D_HPP_
