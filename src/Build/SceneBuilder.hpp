/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#ifndef SCENEBUILDER_HPP
#define SCENEBUILDER_HPP
#include "IBuilder.hpp"
#include "Scene/Camera.hpp"
#include "Scene/Scene.hpp"

namespace RayTracer {
    class SceneBuilder : IBuilder<std::shared_ptr<Scene>> {
    public:
        SceneBuilder& loadFromFile(const std::string& path);

        Camera getCamera() const;

        std::shared_ptr<Scene> build() override;

    private:
        std::string _sceneFile;
        Camera _camera;
        bool _cameraInitialized = false;
    };
}


#endif //SCENEBUILDER_HPP
