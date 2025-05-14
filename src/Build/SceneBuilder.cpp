/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#include "SceneBuilder.hpp"

#include "SceneParser/SceneParser.hpp"

namespace RayTracer {
    SceneBuilder& SceneBuilder::loadFromFile(const std::string& path)
    {
        _sceneFile = path;
        return *this;
    }

    Camera SceneBuilder::getCamera() const
    {
        if (!_cameraInitialized)
            throw std::logic_error("Camera has not been initialized. Call build() first.");
        return _camera;
    }

    std::shared_ptr<Scene> SceneBuilder::build()
    {
        if (_sceneFile.empty())
            throw std::runtime_error("Empty scene file");
        auto scene = std::make_shared<Scene>();
        SceneParser parser(_sceneFile, scene);
        try {
            _camera = parser.initializeCamera();
            _cameraInitialized = true;
            parser.initializeLights();
            parser.initializePrimitives();
        } catch (const SceneParser::SceneParserError& e) {
            throw std::runtime_error(std::string("Failed to parse scene file: ") + e.what());
        }
        return scene;
    }


}
