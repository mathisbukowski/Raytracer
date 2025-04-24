#pragma once

#include "../Utils/Color.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {

class IMaterial {
public:
    virtual ~IMaterial() = default;

    virtual Color getColor(const Vector3D& intersectionPoint, const Vector3D& normal, const Vector3D& viewDirection) const = 0;

    virtual float getReflectivity() const { return 0.0f; }
    virtual float getTransparency() const { return 0.0f; }
    virtual float getRefractiveIndex() const { return 1.0f; }
};

}
