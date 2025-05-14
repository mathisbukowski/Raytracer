/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "SceneParser.hpp"

#include "Factory/ILightFactory.hpp"
#include "Factory/PrimitiveFactory.hpp"

RayTracer::SceneParser::SceneParser(const std::string& sceneFile, const std::shared_ptr<Scene>& scene)
{
    _scene = scene;
    if (sceneFile.empty())
        throw SceneParserError("Scene file cannot be empty");
    _config = std::make_unique<libconfig::Config>();
    try {
        _config->readFile(sceneFile.c_str());
    } catch (const libconfig::FileIOException& e) {
        throw SceneParserError("Could not read file '" + sceneFile + "'");
    }
}

libconfig::Setting& RayTracer::SceneParser::getSceneRoot() const
{
    return this->_config->getRoot();
}

void RayTracer::SceneParser::initializePrimitives()
{
    this->safeLookup([this] {
        if (!this->getSceneRoot().exists("primitives"))
            throw SceneParserError("Primitives not found in config file");
        std::vector<std::string> types = { "spheres", "planes", "cylinders", "cones" };
        const libconfig::Setting& primitives = this->getSceneRoot()["primitives"];

        for (auto& type : types) {
            if (!primitives.exists(type))
                continue;
            const libconfig::Setting& primitiveList = primitives[type.c_str()];
            for (int i = 0; i < primitiveList.getLength(); i++) {
                const libconfig::Setting& setting = primitiveList[i];
                std::cout << "[DEBUG] Parsing primitive #" << i << " of type " << type << "\n";
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
        if (!this->getSceneRoot().exists("camera"))
            throw SceneParserError("Camera not found in config file");
        const libconfig::Setting& camera = (this->getSceneRoot())["camera"];
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
    return {Vector3D(cameraConfig->px, cameraConfig->py, cameraConfig->pz),
        Vector3D(cameraConfig->rx, cameraConfig->ry, cameraConfig->rz),
        cameraConfig->fov, cameraConfig->width, cameraConfig->height};
}

void RayTracer::SceneParser::initializeLights()
{
    this->safeLookup([this] {
        if (!this->getSceneRoot().exists("lights"))
           throw SceneParserError("Light not found in config file");
        const libconfig::Setting& lights = (this->getSceneRoot())["lights"];
        if (!lights.isList())
            throw SceneParserError("Light not found in config file");
        for (int i = 0; i < lights.getLength(); i++) {
            const libconfig::Setting& light = lights[i];
                auto lightFactory = ILightFactory::getFactory(light["type"]);
                auto lightObject = lightFactory->createLight(light);
                _scene->addLight(lightObject);
        }
    });
}
