#pragma once

#include <memory>
#include <string>
#include "../Primitives/IPrimitive.hpp"
#include "../Utils/Color.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {

class PrimitiveFactory {
public:
    static std::shared_ptr<IPrimitive> createSphere(const Vector3D& center, float radius, const Color& color);
    static std::shared_ptr<IPrimitive> createPlane(const Vector3D& normal, float distance, const Color& color);

    static std::shared_ptr<IPrimitive> createCylinder(const Vector3D& base, const Vector3D& axis, float radius, const Color& color);
    static std::shared_ptr<IPrimitive> createCone(const Vector3D& apex, const Vector3D& axis, float angle, const Color& color);
};

}
