/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#ifndef PHOTONMAPPING_HPP
#define PHOTONMAPPING_HPP

#include "../Math/Vector3D.hpp"
#include "../Math/Point3D.hpp"
#include "Utils/Color.hpp"
#include <vector>
#include <algorithm>
#include <memory>

#include "Lights/ILight.hpp"
#include "Primitives/IPrimitive.hpp"
#include "Scene/Scene.hpp"

namespace RayTracer {
    /**
     * @class Photon
     * Represents a photon in the photon mapping algorithm.
     */
    class Photon {
    public:
        /**
         * Constructs a Photon with a position, direction, and power.
         * @param position The position of the photon.
         * @param dir The direction of the photon.
         * @param power The power of the photon.
         */
        Photon(const Point3D& position, const Vector3D& dir, const Color& power);
        /**
         * @brief Get the position of the photon
         * @return The position of the photon
         */
        const Point3D& getPosition() const;
        /**
         * @brief Get the direction of the photon
         * @return The direction of the photon
         */
        const Vector3D& getDirection() const;
        /**
         * @brief Get the power of the photon
         * @return The power of the photon
         */
        const Color& getPower() const;
    private:
        Point3D _position; ///> Position of the photon
        Vector3D _direction; ///> Direction of the photon
        Color _power; ///> Power of the photon
    };


    /**
     * @class KDNode
     * Represents a node in the KDTree.
     */
    class KDNode {
    public:
        /**
         * Constructs a KDNode with a photon and axis.
         * @param photon The photon to be stored in the node.
         * @param axis The axis of the node (0: x, 1: y, 2: z).
         */
        KDNode(std::shared_ptr<Photon> photon, int axis):
        _photon(std::move(photon)), _axis(axis) {}

        std::shared_ptr<Photon> _photon; ///> Photon stored in the node
        int _axis; ///> Axis of the node (0: x, 1: y, 2: z)
        std::unique_ptr<KDNode> _left; ///> Left child node
        std::unique_ptr<KDNode> _right; ///> Right child node
    };

    class KDTree {
    public:
        /**
         * Constructs a KDTree from a list of photons.
         * @param photons The list of photons to be stored in the tree.
         */
        KDTree(const std::vector<std::shared_ptr<Photon>>& photons)
        {
            _root = this->build(photons, 0);
        }

        /**
         * Finds nearby photons within a given radius from the target point.
         * @param point The target point to search around.
         * @param radius The radius for the search.
         * @param maxPhotons The maximum number of photons to gather.
         * @return A vector of found photons.
         */
        void findNearby(const Point3D& point, float radius, int maxPhotons, std::vector<std::shared_ptr<Photon>>& result) const
        {
            this->search(_root.get(), point, radius * radius, maxPhotons, result);
        }
    private:
        std::unique_ptr<KDNode> _root; ///> Root node of the KDTree

        /**
         * Builds the KDTree recursively.
         * @param photons The list of photons to be stored in the tree.
         * @param depth The current depth in the tree.
         * @return A unique pointer to the root node of the KDTree.
         */
        std::unique_ptr<KDNode> build(std::vector<std::shared_ptr<Photon>> photons, int depth);
        /**
         * Recursively searches for photons within a given radius from the target point.
         * @param node The current node in the KDTree.
         * @param target The target point to search around.
         * @param radiusSquared The squared radius for the search.
         * @param maxPhotons The maximum number of photons to gather.
         * @param result The vector to store the found photons.
         */
        void search(KDNode *node, const Point3D& target, float radiusSquared, int maxPhotons,
                    std::vector<std::shared_ptr<Photon>>& result) const;
    };

    /**
     * @class PhotonMapping
     * Implements photon mapping for global illumination.
     */
    class PhotonMapping {
    public:
    /**
     * Default constructor for PhotonMapping.
     */
        PhotonMapping() = default;
        /**
         * Builds the photon map using the provided lights and primitives.
         * @param lights The list of lights in the scene.
         * @param primitives The list of primitives in the scene.
         * @param scene The scene containing the lights and primitives
         */
        void build(const std::vector<std::shared_ptr<ILight>>&, const std::vector<std::shared_ptr<IPrimitive>>&, const Scene&);
        /**
         * Estimates the radiance at a given position using gathered photons.
         * @param position The position where the radiance is estimated.
         * @param normal The normal vector at the position.
         * @param radius The radius for gathering photons.
         * @param maxPhotons The maximum number of photons to gather.
         * @return The estimated radiance at the position.
         */
        Color estimateRadiance(const Point3D& position, const Vector3D& normal, float radius, int maxPhotons) const;

        /**
         * Sets the radius for gathering photons.
         * @param radius The radius for gathering photons.
         */
        void setGatherRadius(float radius) { _radius = radius; }
        /**
         * Sets the maximum number of photons to gather.
         * @param maxPhotons The maximum number of photons.
         */
        void setMaxPhotons(int maxPhotons) { _maxPhotons = maxPhotons; }
        /**
         * Gets the radius for gathering photons.
         * @return The radius for gathering photons.
         */
        float getGatherRadius() const { return _radius; }
        /**
         * Gets the maximum number of photons to gather.
         * @return The maximum number of photons.
         */
        int getMaxPhotons() const { return _maxPhotons; }

        /**
         * Checks if photon mapping is enabled.
         * @return True if photon mapping is enabled, false otherwise.
         */
        bool isEnabled() const { return _enabled && _tree != nullptr; }
        /**
         * Enables or disables photon mapping.
         */
        void enable(bool val = true) { _enabled = val; }
        /**
         * Calculates the squared distance between two points.
         * @param a The first point.
         * @param b The second point.
         * @return The squared distance between the two points.
         */
        static float distanceSquared(const Point3D& a, const Point3D& b);

    private:
        std::vector<std::shared_ptr<Photon>> _photons; ///> List of photons
        std::shared_ptr<KDTree> _tree; ///> KDTree for photon storage
        float _radius = 1.0f; ///> Radius for gathering photons 
        int _maxPhotons = 100; ///> Maximum number of photons to gather
        bool _enabled = true; ///> Enable or disable photon mapping
    };
};



#endif //PHOTONMAPPING_HPP
