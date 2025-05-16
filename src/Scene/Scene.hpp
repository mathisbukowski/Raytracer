/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include <memory>
#include "../Primitives/IPrimitive.hpp"
#include "../Lights/ILight.hpp"
#include "../Utils/Color.hpp"

namespace RayTracer {

    /**
     * @class Scene
     * Represents a scene containing primitives, lights, and a background color.
     */
    class Scene {
    private:
        std::vector<std::shared_ptr<IPrimitive>> _primitives; ///< List of primitives in the scene.
            std::vector<std::shared_ptr<ILight>> _lights; ///< List of lights in the scene.
        Color _backgroundColor; ///< Background color of the scene.

    public:
        /**
         * Default constructor for the Scene class.
         */
        Scene();

        /**
         * Adds a primitive to the scene.
         * @param primitive const std::shared_ptr\<IPrimitive\> & The primitive to add.
         */
        void addPrimitive(const std::shared_ptr<IPrimitive>& primitive);

        /**
         * Adds a light to the scene.
         * @param light const std::shared_ptr\<ILight\> & The light to add.
         */
        void addLight(const std::shared_ptr<ILight>& light);

        /**
         * Sets the background color of the scene.
         * @param color const Color & The background color to set.
         */
        void setBackgroundColor(const Color& color);

        /**
         * Gets the background color of the scene.
         * @return A constant reference to the background color.
         */
        const Color& getBackgroundColor() const;

        /**
         * Finds the nearest intersection of a ray with the primitives in the scene.
         * @param ray const Ray & The ray to test for intersection.
         * @param hitPrimitive std::shared_ptr\<IPrimitive\> & The primitive hit by the ray.
         * @param t float & The distance to the intersection point.
         * @param normal Vector3D & The normal vector at the intersection point.
         * @return True if an intersection is found, false otherwise.
         */
        bool findNearestIntersection(const Ray& ray, std::shared_ptr<IPrimitive>& hitPrimitive,
                                     float& t, Vector3D& normal) const;

        /**
         * Gets the list of primitives in the scene.
         * @return A constant reference to the vector of primitives.
         */
        const std::vector<std::shared_ptr<IPrimitive>>& getPrimitives() const;

        /**
         * Gets the list of lights in the scene.
         * @return A constant reference to the vector of lights.
         */
        const std::vector<std::shared_ptr<ILight>>& getLights() const;
    };

}

#endif /* !SCENE_HPP_ */