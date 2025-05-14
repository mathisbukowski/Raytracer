#include "Core/Engine.hpp"
#include "SceneParser/SceneParser.hpp"
#include <memory>
#include <iostream>

using namespace RayTracer;

int main()
{
    try {
        auto scene = std::make_shared<Scene>();

        std::cout << "[INFO] Creating SceneParser..." << std::endl;
        SceneParser parser("scenes/hard_scene.cfg", scene);

        std::cout << "[INFO] Initializing camera..." << std::endl;
        Camera cam = parser.initializeCamera();

        std::cout << "[INFO] Initializing lights..." << std::endl;
        parser.initializeLights();

        std::cout << "[INFO] Initializing primitives..." << std::endl;
        parser.initializePrimitives();

        std::cout << "[INFO] Creating Engine..." << std::endl;
        Engine engine(800, 600);
        engine.setScene(*scene);
        engine.setCamera(cam);

        std::cout << "[INFO] Rendering..." << std::endl;
        engine.render("output.ppm");

    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "[SUCCESS] Rendered successfully." << std::endl;
    return 0;
}
