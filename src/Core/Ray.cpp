/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Ray
*/

#include "Ray.hpp"

namespace RayTracer {

Ray::Ray(const Vector3D& origin, const Vector3D& direction)
    : _origin(origin), _direction(direction.normalized()) {}

const Vector3D& Ray::getOrigin() const {
    return _origin;
}

const Vector3D& Ray::getDirection() const {
    return _direction;
}

Vector3D Ray::pointAt(float t) const {
    return _origin + _direction * t;
}

}
