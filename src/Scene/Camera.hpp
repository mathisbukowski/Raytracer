/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Camera
*/

#ifndef Camera_HPP_
#define Camera_HPP_

#include "../Math/Vector3D.hpp"
#include "../Core/Ray.hpp"

namespace RayTracer {

class Camera {
private:
    Point3D _position;
    Vector3D _rotation;
    float _fov;
    int _width;
    int _height;

    float _aspectRatio;
    float _viewportHeight;
    float _viewportWidth;
    Vector3D _forward;
    Vector3D _horizontal;
    Vector3D _vertical;
    Point3D _lowerLeftCorner;

public:
    Camera(const Point3D& position, const Vector3D& rotation, float fov, int width, int height);

    Ray generateRay(int x, int y) const;
};

}

#endif // Camera_HPP_
