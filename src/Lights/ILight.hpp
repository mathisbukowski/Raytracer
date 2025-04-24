#pragma once

#include "../Math/Vector3D.hpp"
#include "../Utils/Color.hpp"

namespace RayTracer {

class ILight {
public:
    virtual ~ILight() = default;

    virtual Color calculateIllumination(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDirection) const = 0;

    virtual Vector3D getLightDirection(const Vector3D& point) const = 0;

    virtual bool canCastShadow() const = 0;
};

}
