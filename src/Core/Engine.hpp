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
#include "Photon/PhotonMapping.hpp"

namespace RayTracer {

class Engine {
    public:
        /**
         * Constructor for the Engine class.
         * @param width int The width of the image.
         * @param height int The height of the image.
         */
        Engine(int width, int height);
        /**
         * Destructor for the Engine class.
         */
        ~Engine() = default;
        /**
         * Sets the scene for the engine.
         * @param scene const Scene & The scene to set.
         */
        void setScene(const Scene& scene);
        /**
         * Sets the camera for the engine.
         * @param camera const Camera & The camera to set.
         */
        void setCamera(const Camera& camera);
        /**
         * Renders the scene and saves it to a file.
         * @param outputFile const std::string & The output file name.
         */
        void render(const std::string& outputFile);
        /**
         * Renders the scene and returns the image data.
         * @return A vector of Color representing the image data.
         */
        Color traceRay(const Ray& ray, int depth = 0);
        /**
         * Computes the color at a given point in the scene.
         * @param point const Point3D & The point to compute the color at.
         * @param normal const Vector3D & The normal vector at the point.
         * @param viewDir const Vector3D & The direction from the point to the camera.
         * @return The computed color at the point.
         */
        Color computeLighting(const Point3D& point, const Vector3D& normal, const Vector3D& viewDir);
        /**
         * Computes the reflection color at a given point in the scene.
         * @param ray const Ray & The ray to compute the reflection for.
         * @param point const Point3D & The point to compute the reflection at.
         * @param normal const Vector3D & The normal vector at the point.
         * @param depth int The recursion depth for reflections.
         * @return The computed reflection color at the point.
         */
        Color computeReflection(const Ray& ray, const Point3D& point, const Vector3D& normal, int depth);

        /**
         * Build the photon mapping class
         * @param radius radius of exploitation
         * @param maxPhotons to work with
         */
        void buildPhotonMap(float radius, int maxPhotons);

    void setMultithreadingConfig(bool enable, unsigned int threadCount = 0) {
        _enableMultithreading = enable;
        _threadCount = threadCount;
    }

    private:
        Scene _scene; ///< The scene to be rendered.
        Camera _camera; ///< The camera used for rendering.
        int _width; ///< The width of the image.
        int _height; ///< The height of the image.
        bool _cameraSet = false; ///< Flag to check if the camera is set.
        bool _sceneSet = false; ///< Flag to check if the scene is set.
        static constexpr int MAX_DEPTH = 5; ///< Maximum recursion depth for reflections.
        bool _enableMultithreading = true;
        unsigned int _threadCount = 0;
        std::shared_ptr<PhotonMapping> _photonMapping = std::make_shared<PhotonMapping>(); ///> PhotonMapping Class

        /**
         *
         */
        void renderBlock(std::vector<Color>& framebuffer, int startY, int endY);
        /**
         * Computes the reflected ray based on the incident ray and the normal at the intersection point.
         * @param origin const Point3D & The origin of the ray.
         * @param incident const Vector3D & The incident ray direction.
         * @param normal const Vector3D & The normal vector at the intersection point.
         * @return The reflected ray as a Vector3D.
         */
        Ray computeReflectedRay(const Point3D& origin, const Vector3D& incident, const Vector3D& normal);
        Ray computeRefractedRay(const Ray& ray, const Point3D& point, const Vector3D& normal, float refractiveIndex);
        float computeFresnelReflectance(const Vector3D& incident, const Vector3D& normal, float refractiveIndex);
};

}
#endif // Engine_HPP_
