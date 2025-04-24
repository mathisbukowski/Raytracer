#pragma once

#include <memory>
#include "../Math/Vector3D.hpp"
#include "../Core/Ray.hpp"
#include "../Materials/IMaterial.hpp"

namespace RayTracer {

class IPrimitive {
public:
    virtual ~IPrimitive() = default;

    virtual bool intersect(const Ray& ray, float& t, Vector3D& normal) const = 0;

    virtual void translate(const Vector3D& translation) = 0;

    virtual void rotate(const Vector3D& rotation) = 0;

    virtual std::shared_ptr<IMaterial> getMaterial() const = 0;

    virtual void setMaterial(const std::shared_ptr<IMaterial>& material) = 0;
};

}
