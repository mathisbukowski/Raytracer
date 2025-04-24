/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <memory>

#include "Scene/Scene.hpp"

namespace RayTracer {
    class Engine {
        class EngineError : public std::exception {
            public:
                EngineError(const std::string& message): _message(message) {}
                const char* what() const { return _message.c_str(); }
            private:
                std::string _message;
        };
        public:
            Engine();
            ~Engine();
        private:
            std::shared_ptr<Scene> _scene;
            std::shared_ptr<Camera> _camera;
    };
};
#endif //ENGINE_HPP
