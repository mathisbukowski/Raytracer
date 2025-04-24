/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

namespace RayTracer {

class Vector3D {
public:
    float x, y, z;

    Vector3D();
    Vector3D(float x, float y, float z);

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;
    Vector3D operator/(float scalar) const;

    float dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;
    float length() const;
    Vector3D normalized() const;
};

Vector3D operator*(float scalar, const Vector3D& v);

}

#endif // VECTOR3D_HPP_
