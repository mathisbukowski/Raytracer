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
    class Photon {
    public:
        Photon(const Point3D& position, const Vector3D& dir, const Color& power);
        const Point3D& getPosition() const;
        const Vector3D& getDirection() const;
        const Color& getPower() const;
    private:
        Point3D _position;
        Vector3D _direction;
        Color _power;
    };

    class KDNode {
    public:
        KDNode(std::shared_ptr<Photon> photon, int axis):
        _photon(std::move(photon)), _axis(axis) {}

        std::shared_ptr<Photon> _photon;
        int _axis;
        std::unique_ptr<KDNode> _left;
        std::unique_ptr<KDNode> _right;
    };

    class KDTree {
    public:
        KDTree(const std::vector<std::shared_ptr<Photon>>& photons)
        {
            _root = this->build(photons, 0);
        }

        void findNearby(const Point3D& point, float radius, int maxPhotons, std::vector<std::shared_ptr<Photon>>& result) const
        {
            this->search(_root.get(), point, radius * radius, maxPhotons, result);
        }
    private:
        std::unique_ptr<KDNode> _root;

        std::unique_ptr<KDNode> build(std::vector<std::shared_ptr<Photon>> photons, int depth);
        void search(KDNode* node, const Point3D& target, float radiusSquared, int maxPhotons,
                    std::vector<std::shared_ptr<Photon>>& result) const;
    };

    class PhotonMapping {
    public:
        PhotonMapping() = default;

        void build(const std::vector<std::shared_ptr<ILight>>& lights, const std::vector<std::shared_ptr<IPrimitive>>& objects, const Scene& scene);

        Color estimateRadiance(const Point3D& position, const Vector3D& normal, float radius = 100.0f, int maxPhotons = 1000) const;
        static float distanceSquared(const Point3D& a, const Point3D& b);
    private:

        std::vector<std::shared_ptr<Photon>> _photons;
        std::shared_ptr<KDTree> _tree;


    };
};



#endif //PHOTONMAPPING_HPP
