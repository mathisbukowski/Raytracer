/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#ifndef ENGINEBUILDER_HPP
#define ENGINEBUILDER_HPP
#include "IBuilder.hpp"
#include "Core/Engine.hpp"


namespace RayTracer {
    class EngineBuilder : IBuilder<Engine> {
    public:
        Engine build() override;

        EngineBuilder &setResolution(int width, int height);

        EngineBuilder &setCamera(const Camera& c);

        EngineBuilder &setScene(const std::shared_ptr<Scene>& s);
    private:
        int _width = 800;
        int _height = 600;
        Camera _camera;
        bool _hasCamera = false;
        std::shared_ptr<Scene> _scene;
    };
}



#endif //ENGINEBUILDER_HPP
