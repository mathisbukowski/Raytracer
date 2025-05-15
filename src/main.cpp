/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** main
*/

#include "Core/Engine.hpp"
#include "SceneParser/SceneParser.hpp"
#include <memory>
#include <iostream>
#include "Build/EngineBuilder.hpp"
#include "Build/SceneBuilder.hpp"

int rendererEngine(std::shared_ptr<RayTracer::Scene> scene, RayTracer::Camera cam)
{
    try {
        RayTracer::EngineBuilder engineBuilder;
        RayTracer::Engine engine = engineBuilder.setResolution(800, 600).setCamera(cam).setScene(scene).build();
        std::cout << "[INFO] Rendering..." << std::endl;
        engine.render("output.ppm");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (!av || ac > 2 || !av[1]) {
        std::cerr << "Usage: " << av[0] << " <SCENE_FILE>" << std::endl;
        return 84;
    }
    std::shared_ptr<RayTracer::Scene> scene;
    RayTracer::Camera cam;
    try {
        RayTracer::SceneBuilder sceneBuilder;
        scene = sceneBuilder.loadFromFile(av[1]).build();
        cam = sceneBuilder.getCamera();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    if (rendererEngine(scene, cam) == 84)
        return 84;
    std::cout << "[SUCCESS] Rendered successfully." << std::endl;
    return 0;
}
