/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#include "PhotonMapping.hpp"

#include <utility>
#include <random>


namespace RayTracer {
    Photon::Photon(const Point3D& position, const Vector3D& dir, const Color& power):
    _position(position), _direction(dir), _power(power) {}

    const Point3D& Photon::getPosition() const
    {
        return _position;
    }

    const Vector3D& Photon::getDirection() const
    {
        return _direction;
    }

    const Color& Photon::getPower() const
    {
        return _power;
    }

    float PhotonMapping::distanceSquared(const Point3D& a, const Point3D& b)
    {
        return (a - b).lengthSquared();
    }

    void KDTree::search(KDNode* node, const Point3D& target, float radiusSquared, int maxPhotons, std::vector<std::shared_ptr<Photon>>& result) const
    {
        if (!node)
            return;

        const Point3D& pos = node->_photon->getPosition();
        float dist2 = PhotonMapping::distanceSquared(pos, target);
        if (dist2 <= radiusSquared)
            result.push_back(node->_photon);

        float diff = (node->_axis == 0 ? target.x - pos.x :
                          node->_axis == 1 ? target.y - pos.y :
                          target.z - pos.z);

        KDNode* near = diff < 0 ? node->_left.get() : node->_right.get();
        KDNode* far  = diff < 0 ? node->_right.get() : node->_left.get();

        search(near, target, radiusSquared, maxPhotons, result);
        if (diff * diff <= radiusSquared && result.size() < static_cast<size_t>(maxPhotons)) {
            search(far, target, radiusSquared, maxPhotons, result);
        }
    }

    std::unique_ptr<KDNode> KDTree::build(std::vector<std::shared_ptr<Photon>> photons, int depth)
    {
        if (photons.empty())
            return nullptr;
        int axis = depth % 3;
        auto comparator = [axis](const std::shared_ptr<Photon>& a, const std::shared_ptr<Photon>& b) {
            const Point3D& pa = a->getPosition();
            const Point3D& pb = b->getPosition();
            return (axis == 0 ? pa.x : axis == 1 ? pa.y : pa.z) <
                (axis == 0 ? pb.x : axis == 1 ? pb.y : pb.z);
        };

        std::sort(photons.begin(), photons.end(), comparator);
        size_t median = photons.size() / 2;

        auto node = std::make_unique<KDNode>(photons[median], axis);
        std::vector<std::shared_ptr<Photon>> left(photons.begin(), photons.begin() + median);
        std::vector<std::shared_ptr<Photon>> right(photons.begin() + median + 1, photons.end());

        node->_left = build(left, depth + 1);
        node->_right = build(right, depth + 1);

        return node;
    }



    void PhotonMapping::build(const std::vector<std::shared_ptr<ILight>>& lights,
                          const std::vector<std::shared_ptr<IPrimitive>>& objects, const Scene& scene)
    {
        _photons.clear();
        (void)objects;
        const int photonCount = 100000;
        std::default_random_engine rng;
        std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

        for (const auto& light : lights) {
            for (size_t i = 0; i < photonCount / lights.size(); ++i) {
                Vector3D dir(dist(rng), dist(rng), dist(rng));
                if (dir.lengthSquared() < 0.01f) continue;

                Ray photonRay(light->getPosition(), dir);

                std::shared_ptr<IPrimitive> hitObj;
                float t;
                Vector3D normal;

                if (scene.findNearestIntersection(photonRay, hitObj, t, normal)) {
                    Point3D hitPoint = photonRay.pointAt(t);
                    Color power = light->getColor() * light->getIntensity() * 100.0f;

                    _photons.push_back(std::make_shared<Photon>(hitPoint, dir.normalized(), power));
                }
            }
        }
        _tree = std::make_shared<KDTree>(_photons);
    }

    Color PhotonMapping::estimateRadiance(const Point3D& position, const Vector3D& normal, float radius, int maxPhotons) const
    {
        if (!_tree)
            return Color(0, 0, 0);

        std::vector<std::shared_ptr<Photon>> nearby;
        _tree->findNearby(position, radius, maxPhotons, nearby);

        Color accumulated(0, 0, 0);
        for (const auto& photon : nearby) {
            float dot = std::max(0.0f, normal.dot(-photon->getDirection()));
            accumulated += photon->getPower() * dot;
        }

        float area = static_cast<float>(M_PI * radius * radius);
        return accumulated / std::max(1.0f, static_cast<float>(nearby.size()) * area);
    }
}