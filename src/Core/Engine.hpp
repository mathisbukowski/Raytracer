/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Engine
*/

#ifndef Engine_HPP_
#define Engine_HPP_

#include <string>
#include <memory>
#include <vector>
#include "../Scene/Scene.hpp"
#include "../Scene/Camera.hpp"
#include "../Utils/Color.hpp"
#include "../Core/Ray.hpp"

namespace RayTracer {

class Engine {
private:
    Scene _scene;
    Camera _camera;
    int _width;
    int _height;

    bool _cameraSet = false;
    bool _sceneSet = false;
    static constexpr int MAX_DEPTH = 5;
    Ray computeReflectedRay(const Point3D& origin, const Vector3D& incident, const Vector3D& normal);

public:
    Engine(int width, int height);

    void setScene(const Scene& scene);
    void setCamera(const Camera& camera);

    void render(const std::string& outputFile);
    Color traceRay(const Ray& ray, int depth = 0);
    Color computeLighting(const Point3D& point, const Vector3D& normal, const Vector3D& viewDir);
    Color computeReflection(const Ray& ray, const Point3D& point, const Vector3D& normal, int depth);
};

}
#endif // Engine_HPP_
