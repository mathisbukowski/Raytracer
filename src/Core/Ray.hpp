/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Ray
*/

#ifndef Ray_HPP_
#define Ray_HPP_

#include "../Math/Vector3D.hpp"

namespace RayTracer {

class Ray {
private:
    Vector3D _origin;
    Vector3D _direction;

public:
    Ray(const Vector3D& origin, const Vector3D& direction);

    const Vector3D& getOrigin() const;
    const Vector3D& getDirection() const;

    Vector3D pointAt(float t) const;
};

}

#endif //Ray_HPP_
