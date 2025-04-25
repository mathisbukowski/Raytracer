/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "SceneParser.hpp"

#include "Factory/PrimitiveFactory.hpp"

RayTracer::SceneParser::SceneParser(const std::string& sceneFile, const std::shared_ptr<Scene>& scene): _camera()
{
    _scene = scene;
    if (sceneFile.empty())
        throw SceneParserError("Scene file cannot be empty");
    libconfig::Config config;
    config.readFile(sceneFile.c_str());
    _sceneRoot = std::make_shared<libconfig::Setting>(config.getRoot());
    _camera = this->initializeCamera();
}

std::shared_ptr<libconfig::Setting> RayTracer::SceneParser::getSceneRoot() const
{
    return _sceneRoot;
}

void RayTracer::SceneParser::initializePrimitives()
{
    this->safeLookup([this] {
        if (!_sceneRoot->exists("primitives"))
            throw SceneParserError("Primitives not found in config file");
        std::vector<std::string> types = { "spheres", "planes", "cylinders", "cones" };
        const libconfig::Setting& primitives = (_sceneRoot.operator*())["primitives"];

        for (auto& type : types) {
            if (!primitives.exists(type))
                continue;
            const libconfig::Setting& primitiveList = primitives[type.c_str()];
            for (int i = 0; i < primitiveList.getLength(); i++) {
                const libconfig::Setting& setting = primitiveList[i];
                auto factory = IPrimitiveFactory::getFactory(type);
                auto primitive = factory->createPrimitive(setting);
                _scene->addPrimitive(primitive);
            }
        }
    });
}

RayTracer::Camera RayTracer::SceneParser::initializeCamera()
{
    auto cameraConfig = std::make_shared<CameraConfig>();

    this->safeLookup([this, cameraConfig] {
        if (!_sceneRoot->exists("camera"))
            throw SceneParserError("Camera not found in config file");
        const libconfig::Setting& camera = (_sceneRoot.operator*())["camera"];
        camera["resolution"].lookupValue("width", cameraConfig->width);
        camera["resolution"].lookupValue("height", cameraConfig->height);
        camera["rotation"].lookupValue("x", cameraConfig->rx);
        camera["rotation"].lookupValue("y", cameraConfig->ry);
        camera["rotation"].lookupValue("z", cameraConfig->rz);
        camera.lookupValue("fov", cameraConfig->fov);
        camera["position"].lookupValue("x", cameraConfig->px);
        camera["position"].lookupValue("y", cameraConfig->py);
        camera["position"].lookupValue("z", cameraConfig->pz);
    });
    return {Vector3D(cameraConfig->px, cameraConfig->py, cameraConfig->pz), Vector3D(cameraConfig->rx, cameraConfig->ry, cameraConfig->rz), cameraConfig->fov, cameraConfig->width, cameraConfig->height};
}

void RayTracer::SceneParser::initializeLights()
{
    this->safeLookup([this] {
        if (!_sceneRoot->exists("lights"))
           throw SceneParserError("Light not found in config file");
        const libconfig::Setting& lights = (_sceneRoot.operator*())["lights"];

    });
}

