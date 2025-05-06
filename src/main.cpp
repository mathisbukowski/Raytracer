#include "Core/Engine.hpp"
#include "SceneParser/SceneParser.hpp"
#include <memory>
#include <iostream>

using namespace RayTracer;

int main()
{
    try {
        auto scene = std::make_shared<Scene>();

        SceneParser parser("scenes/basic_scene.cfg", scene);
        Camera cam = parser.initializeCamera();
        parser.initializeLights();
        parser.initializePrimitives();
        Engine engine(400, 300);
        engine.setScene(*scene);
        engine.setCamera(cam);
        engine.render("output.ppm");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
