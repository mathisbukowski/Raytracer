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

int main(int ac, char **av)
{
    if (!av || ac > 2 || !av[1]) {
        std::cerr << "Usage: " << av[0] << " <SCENE_FILE>" << std::endl;
        return 84;
    }
    try {
        auto scene = std::make_shared<RayTracer::Scene>();

        std::cout << "[INFO] Creating SceneParser..." << std::endl;
        RayTracer::SceneParser parser(av[1], scene);

        std::cout << "[INFO] Initializing camera..." << std::endl;
        RayTracer::Camera cam = parser.initializeCamera();

        std::cout << "[INFO] Initializing lights..." << std::endl;
        parser.initializeLights();

        std::cout << "[INFO] Initializing primitives..." << std::endl;
        parser.initializePrimitives();

        std::cout << "[INFO] Creating Engine..." << std::endl;
        RayTracer::Engine engine(800, 600);
        engine.setScene(scene.operator*());
        engine.setCamera(cam);

        std::cout << "[INFO] Rendering..." << std::endl;
        engine.render("output.ppm");

    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception: " << e.what() << std::endl;
        return 84;
    }

    std::cout << "[SUCCESS] Rendered successfully." << std::endl;
    return 0;
}
