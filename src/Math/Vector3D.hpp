#pragma once

#include <cmath>

namespace RayTracer {

class Vector3D {
public:
    float x, y, z;

    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    Vector3D operator*(float scalar) const;
    Vector3D operator/(float scalar) const;

    float dot(const Vector3D& v) const;
    Vector3D cross(const Vector3D& v) const;

    float length() const;
    Vector3D normalized() const;
};

Vector3D operator*(float scalar, const Vector3D& v);

}
