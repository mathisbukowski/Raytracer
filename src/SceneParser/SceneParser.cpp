/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#include "SceneParser.hpp"

#include "Factory/PrimitiveFactory.hpp"

RayTracer::SceneParser::SceneParser(const std::string& sceneFile, const std::shared_ptr<Camera>& camera, const std::shared_ptr<Scene>& scene)
{
    _camera = camera;
    _scene = scene;
    if (sceneFile.empty())
        throw SceneParserError("Scene file cannot be empty");
    libconfig::Config config;
    config.readFile(sceneFile.c_str());
    _sceneRoot = std::make_shared<libconfig::Setting>(config.getRoot());
}

std::shared_ptr<libconfig::Setting> RayTracer::SceneParser::getSceneRoot() const
{
    return _sceneRoot;
}

void RayTracer::SceneParser::initializePrimitives()
{
    this->safeLookup([this]() {
        if (!_sceneRoot->exists("primitives"))
            throw SceneParserError("Primitives not found in config file");
        std::vector<std::string> types = { "spheres", "planes", "cylinders", "cones" };
        const libconfig::Setting& primitives = (_sceneRoot.operator*())["primitives"];

        for (auto& type : types) {
            if (!primitives.exists(type))
                continue;
            const libconfig::Setting& primitiveList = primitives[type.c_str()];
            for (int i = 0; i < primitiveList.getLength(); ++i) {
                const libconfig::Setting& setting = primitiveList[i];
                auto factory = IPrimitiveFactory::getFactory(type);
                auto primitive = factory->createPrimitive(setting);
                _scene->addPrimitive(primitive);
            }
        }
    });
}