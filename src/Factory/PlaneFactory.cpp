/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "PlaneFactory.hpp"

#include "IMaterialFactory.hpp"
#include "Primitives/Plane/Plane.hpp"

std::shared_ptr<RayTracer::IPrimitive> RayTracer::PlaneFactory::createPrimitive(const libconfig::Setting& settings)
{
    const libconfig::Setting& normalSetting = settings.lookup("normal");
    float nx = 0, ny = 0, nz = 0;
    normalSetting.lookupValue("x", nx);
    normalSetting.lookupValue("y", ny);
    normalSetting.lookupValue("z", nz);
    Vector3D normal(nx, ny, nz);

    const libconfig::Setting& pointSetting = settings.lookup("point");
    float px = 0, py = 0, pz = 0;
    pointSetting.lookupValue("x", px);
    pointSetting.lookupValue("y", py);
    pointSetting.lookupValue("z", pz);
    Point3D point(px, py, pz);

    std::shared_ptr<IMaterial> material = nullptr;
    if (settings.exists("material")) {
        const libconfig::Setting& materialSetting = settings.lookup("material");
        std::string materialType = materialSetting.lookup("type");
        auto factory = IMaterialFactory::getFactory(materialType);
        material = factory->createMaterial(materialSetting);
    }

    return std::make_shared<Plane>(normal, point, material);
}
