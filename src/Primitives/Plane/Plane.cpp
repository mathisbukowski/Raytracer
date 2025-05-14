/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

RayTracer::Plane::Plane(const Vector3D& normal, const Point3D& point, const std::shared_ptr<IMaterial>& material)
    : _point(point), _normal(normal.normalized()), _material(material)
{
    _distance = _normal.dot(_point);
    _axis = "custom";
    _position = 0.0f;
    _color = material ? material->getColor() : Color(1, 1, 1);
}

bool RayTracer::Plane::intersect(const RayTracer::Ray &ray, float &t, RayTracer::Vector3D &normal) const
{
    float denominator = _normal.dot(ray.getDirection());
    if (std::abs(denominator) > 1e-6) {
        Vector3D pos = _point - ray.getOrigin();
        t = pos.dot(_normal) / denominator;
        if (t >= 0) {
            normal = _normal;
            return true;
        }
    }
    return false;
}

void RayTracer::Plane::translate(const RayTracer::Vector3D &translation)
{
    _point = _point + translation;
    _distance = _normal.dot(_point);
    if (_axis == "X")
        _position = _point.x;
    else if (_axis == "Y")
        _position = _point.y;
    else if (_axis == "Z")
        _position = _point.z;
}

void RayTracer::Plane::rotate(const RayTracer::Vector3D &rotation)
{
    float angleX = rotation.x * static_cast<float>(M_PI) / 180.0f;
    float angleY = rotation.y * static_cast<float>(M_PI) / 180.0f;
    float angleZ = rotation.z * static_cast<float>(M_PI) / 180.0f;

    if (angleX != 0) {
        float y = _normal.y * std::cos(angleX) - _normal.z * std::sin(angleX);
        float z = _normal.y * std::sin(angleX) + _normal.z * std::cos(angleX);
        _normal.y = y;
        _normal.z = z;
    }
    if (angleY != 0) {
        float x = _normal.x * std::cos(angleY) + _normal.z * std::sin(angleY);
        float z = -_normal.x * std::sin(angleY) + _normal.z * std::cos(angleY);
        _normal.x = x;
        _normal.z = z;
    }
    if (angleZ != 0) {
        float x = _normal.x * std::cos(angleZ) - _normal.y * std::sin(angleZ);
        float y = _normal.x * std::sin(angleZ) + _normal.y * std::cos(angleZ);
        _normal.x = x;
        _normal.y = y;
    }
    Vector3D normalized = _normal.normalized();
    _distance = _normal.dot(_point);
    float absX = std::abs(normalized.x);
    float absY = std::abs(normalized.y);
    float absZ = std::abs(normalized.z);
    if (absX >= absY && absX >= absZ) {
        std::string newXAxis = "X";
        _axis = newXAxis;
        _position = _point.x;
    } else if (absY >= absX && absY >= absZ) {
        std::string newYAxis = "Y";
        _axis = newYAxis;
        _position = _point.y;
    } else {
        std::string newXAxis = "Z";
        _axis = newXAxis;
        _position = _point.z;
    }
}

std::shared_ptr<RayTracer::IMaterial> RayTracer::Plane::getMaterial() const
{
    return _material;
}

void RayTracer::Plane::setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material)
{
    _material = material;
}

const RayTracer::Point3D &RayTracer::Plane::getPoint() const
{
    return _point;
}

const RayTracer::Vector3D &RayTracer::Plane::getNormal() const
{
    return _normal;
}

float RayTracer::Plane::getDistance() const
{
    return _distance;
}

const RayTracer::Color &RayTracer::Plane::getColor() const
{
    return _color;
}

const std::string &RayTracer::Plane::getAxis() const
{
    return _axis;
}

float RayTracer::Plane::getPosition() const
{
    return _position;
}
