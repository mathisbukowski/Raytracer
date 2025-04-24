#pragma once

#include <vector>
#include <memory>
#include "../Primitives/IPrimitive.hpp"
#include "../Lights/ILight.hpp"
#include "../Utils/Color.hpp"

namespace RayTracer {

class Scene {
private:
    std::vector<std::shared_ptr<IPrimitive>> _primitives;
    std::vector<std::shared_ptr<ILight>> _lights;
    Color _backgroundColor;

public:
    Scene();

    void addPrimitive(const std::shared_ptr<IPrimitive>& primitive);
    void addLight(const std::shared_ptr<ILight>& light);

    void setBackgroundColor(const Color& color);
    const Color& getBackgroundColor() const;

    bool findNearestIntersection(const Ray& ray, std::shared_ptr<IPrimitive>& hitPrimitive,
                                 float& t, Vector3D& normal) const;

    const std::vector<std::shared_ptr<IPrimitive>>& getPrimitives() const;
    const std::vector<std::shared_ptr<ILight>>& getLights() const;
};

}
