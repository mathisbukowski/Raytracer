/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_


namespace RayTracer {
    class Vector3D;

class Point3D {
public:
    float x, y, z;

    Point3D();
    Point3D(float x, float y, float z);
    Point3D(const Vector3D& v);

    Point3D operator+(const Vector3D& vec) const;
    Point3D& operator+=(const Vector3D& vec);
    Vector3D operator-(const Point3D& other) const;

    bool operator==(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;
};

}

#endif // POINT3D_HPP_
