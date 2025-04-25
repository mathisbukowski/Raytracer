/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace RayTracer {

Point3D::Point3D() : x(0), y(0), z(0) {}

Point3D::Point3D(float x, float y, float z) : x(x), y(y), z(z) {}

Point3D::Point3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}

Point3D Point3D::operator+(const Vector3D& vec) const {
    return Point3D(x + vec.x, y + vec.y, z + vec.z);
}

Point3D& Point3D::operator+=(const Vector3D& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vector3D Point3D::operator-(const Point3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

bool Point3D::operator==(const Point3D& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Point3D::operator!=(const Point3D& other) const {
    return !(*this == other);
}

}
