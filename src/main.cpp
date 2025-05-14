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

int initializeParser(char** av, std::shared_ptr<RayTracer::Scene> scene, RayTracer::Camera& cam)
{
    try {
        std::cout << "[INFO] Creating SceneParser..." << std::endl;
        RayTracer::SceneParser parser(av[1], scene);

        std::cout << "[INFO] Initializing camera..." << std::endl;
        cam = parser.initializeCamera();

        std::cout << "[INFO] Initializing lights..." << std::endl;
        parser.initializeLights();

        std::cout << "[INFO] Initializing primitives..." << std::endl;
        parser.initializePrimitives();
    } catch (const RayTracer::SceneParser::SceneParserError& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int rendererEngine(std::shared_ptr<RayTracer::Scene> scene, RayTracer::Camera cam, RayTracer::Engine& engine)
{
    try {
        std::cout << "[INFO] R Engine..." << std::endl;
        engine.setScene(scene.operator*());
        engine.setCamera(cam);
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
    auto scene = std::make_shared<RayTracer::Scene>();
    RayTracer::Camera cam;
    RayTracer::Engine engine(800, 600);

    if (initializeParser(av, scene, cam) == 84)
        return 84;
    if (rendererEngine(scene, cam, engine) == 84)
        return 84;
    std::cout << "[SUCCESS] Rendered successfully." << std::endl;
    return 0;
}
