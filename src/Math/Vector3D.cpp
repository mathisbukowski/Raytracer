/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

namespace RayTracer {

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(float scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

Vector3D Vector3D::operator/(float scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

float Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalized() const {
    float len = length();
    if (len == 0.0f)
        return *this;
    return *this / len;
}

Vector3D operator*(float scalar, const Vector3D& v) {
    return v * scalar;
}

}
