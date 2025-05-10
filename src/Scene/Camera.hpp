/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Camera
*/

#ifndef Camera_HPP_
#define Camera_HPP_

#include "../Math/Vector3D.hpp"
#include "../Core/Ray.hpp"

namespace RayTracer {

    /**
     * @class Camera
     * Represents a camera in 3D space.
     */
    class Camera {
        private:
            Point3D _position; ///< The position of the camera in 3D space.
            Vector3D _rotation; ///< The rotation of the camera in 3D space.
            float _fov; ///< The field of view of the camera in degrees.
            int _width; ///< The width of the camera's viewport in pixels.
            int _height; ///< The height of the camera's viewport in pixels.

            float _aspectRatio; ///< The aspect ratio of the camera's viewport.
            float _viewportHeight; ///< The height of the viewport in world units.
            float _viewportWidth; ///< The width of the viewport in world units.
            Vector3D _forward; ///< The forward direction vector of the camera.
            Vector3D _horizontal; ///< The horizontal direction vector of the camera.
            Vector3D _vertical; ///< The vertical direction vector of the camera.
            Point3D _lowerLeftCorner; ///< The lower left corner of the camera's viewport in world coordinates.

        public:
            /**
             * Constructor for the Camera class.
             * @param position The position of the camera in 3D space.
             * @param rotation The rotation of the camera in 3D space.
             * @param fov The field of view of the camera in degrees.
             * @param width The width of the camera's viewport in pixels.
             * @param height The height of the camera's viewport in pixels.
             */
            Camera(const Point3D& position, const Vector3D& rotation, float fov, int width, int height);

            /**
             * Destructor for the Camera class.
             */
            ~Camera() = default;
            /**
             * Generates a ray from the camera through a pixel in the viewport.
             * @param x The x coordinate of the pixel.
             * @param y The y coordinate of the pixel.
             * @return A Ray object representing the ray from the camera through the pixel.
             */
            Ray generateRay(int x, int y) const;

            /**
             * Gets the width of the camera.
             * @return The width of the camera as an integer.
             */
            int getWidth() const { return _width; }
            /**
             * Gets the height of the camera.
             * @return The height of the camera as an integer.
             */
            int getHeight() const { return _height; }
    };

}

#endif // Camera_HPP_
