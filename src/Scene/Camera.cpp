/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include <cmath>

namespace RayTracer {

Camera::Camera(const Point3D& position, const Vector3D& rotation, float fov, int width, int height)
    : _position(position), _rotation(rotation), _fov(fov), _width(width), _height(height)
{
    _aspectRatio = static_cast<float>(width) / height;
    _viewportHeight = 2.0f * std::tan((_fov * M_PI / 180.0f) / 2.0f);
    _viewportWidth = _aspectRatio * _viewportHeight;

    _forward = eulerRotation(Vector3D(0, 0, 1), _rotation);
    Vector3D up = Vector3D(0, 1, 0);

    _horizontal = _forward.cross(up).normalized() * _viewportWidth;
    _vertical = _horizontal.cross(_forward).normalized() * _viewportHeight;
    _lowerLeftCorner = _position + _forward - _horizontal / 2 - _vertical / 2;
}

Ray Camera::generateRay(int x, int y) const {
    float u = static_cast<float>(x) / (_width - 1);
    float v = static_cast<float>(y) / (_height - 1);

    Vector3D direction = (_lowerLeftCorner + u * _horizontal + v * _vertical) - _position;
    return Ray(_position, direction);
}

}
