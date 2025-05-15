/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#include "EngineBuilder.hpp"

namespace RayTracer {
    Engine EngineBuilder::build()
    {
        if (!_scene)
            throw std::runtime_error("EngineBuilder::build(): no scene specified");
        if (!_hasCamera)
            throw std::runtime_error("EngineBuilder::build(): no camera specified");
        Engine engine(_width, _height);

        engine.setCamera(_camera);
        engine.setScene(_scene.operator*());
        return engine;
    }

    EngineBuilder& EngineBuilder::setCamera(const Camera& c)
    {
        _camera = c;
        _hasCamera = true;
        return *this;
    }

    EngineBuilder& EngineBuilder::setScene(const std::shared_ptr<Scene>& s)
    {
        _scene = std::move(s);
        return *this;
    }

    EngineBuilder& EngineBuilder::setResolution(int width, int height)
    {
        _width = width;
        _height = height;
        return *this;
    }
}