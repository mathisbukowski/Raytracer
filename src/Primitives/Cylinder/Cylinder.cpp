/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

RayTracer::Cylinder::Cylinder(const Point3D &base, const Vector3D &axis, float radius, float height,
                              Color color, const std::shared_ptr<IMaterial> &material)
{
    _base = base;
    _axis = axis.normalized();
    _radius = radius;
    _height = height;
    _color = color;
    _material = material;

}

bool RayTracer::Cylinder::intersect(const RayTracer::Ray &ray, float &t, RayTracer::Vector3D &normal) const
{
    Vector3D rayDir = ray.getDirection();
    Point3D rayOrigin = ray.getOrigin();
    Vector3D originToBase = rayOrigin - _base;
    float dotDirAxis = rayDir.dot(_axis);
    float dotOrigAxis = originToBase.dot(_axis);
    Vector3D dirPerpToAxis = rayDir - _axis * dotDirAxis;
    Vector3D origPerpToAxis = originToBase - _axis * dotOrigAxis;
    float a = dirPerpToAxis.dot(dirPerpToAxis);
    float b = 2.0f * origPerpToAxis.dot(dirPerpToAxis);
    float c = origPerpToAxis.dot(origPerpToAxis) - _radius * _radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return false;
    float t1 = (-b - sqrt(discriminant)) / (2.0f * a);
    float t2 = (-b + sqrt(discriminant)) / (2.0f * a);
    float t_cylinder = (t1 > 0.001f && (t2 < 0.001f || t1 < t2)) ? t1 : t2;
    if (t_cylinder < 0.001f)
        return false;
    Point3D hitPoint = rayOrigin + rayDir * t_cylinder;
    float hitHeight = (hitPoint - _base).dot(_axis);
    if (hitHeight < 0 || hitHeight > _height)
        return false;
    float t_cap = -1;
    Vector3D cap_normal;
    bool hit_cap = false;
    float t_base_cap = (_base - rayOrigin).dot(_axis) / dotDirAxis;
    if (t_base_cap > 0.001f) {
        Point3D base_hit = rayOrigin + rayDir * t_base_cap;
        if ((base_hit - _base).length() <= _radius) {
            t_cap = t_base_cap;
            cap_normal = -_axis;
            hit_cap = true;
        }
    }
    Point3D top_center = _base + _axis * _height;
    float t_top_cap = (top_center - rayOrigin).dot(_axis) / dotDirAxis;
    if (t_top_cap > 0.001f && (!hit_cap || t_top_cap < t_cap)) {
        Point3D top_hit = rayOrigin + rayDir * t_top_cap;
        if ((top_hit - top_center).length() <= _radius) {
            t_cap = t_top_cap;
            cap_normal = _axis;
            hit_cap = true;
        }
    }
    if (hit_cap && (!hit_cap || t_cap < t_cylinder)) {
        t = t_cap;
        normal = cap_normal;
    } else {
        t = t_cylinder;
        Point3D hit = rayOrigin + rayDir * t;
        Vector3D baseTo_hit = hit - _base;
        float projOnAxis = baseTo_hit.dot(_axis);
        Point3D centerOnAxis = _base + _axis * projOnAxis;
        normal = (hit - centerOnAxis).normalized();
    }
    return true;
}

void RayTracer::Cylinder::translate(const RayTracer::Vector3D &translation)
{
    _base = _base + translation;
}

void RayTracer::Cylinder::rotate(const RayTracer::Vector3D &rotation)
{
    float cosX = cosf(rotation.x);
    float sinX = sinf(rotation.x);
    float cosY = cosf(rotation.y);
    float sinY = sinf(rotation.y);
    float cosZ = cosf(rotation.z);
    float sinZ = sinf(rotation.z);
    float yNew = _axis.y * cosX - _axis.z * sinX;
    float zNew = _axis.y * sinX + _axis.z * cosX;
    _axis.y = yNew;
    _axis.z = zNew;
    float xNew = _axis.x * cosY + _axis.z * sinY;
    zNew = -_axis.x * sinY + _axis.z * cosY;
    _axis.x = xNew;
    _axis.z = zNew;
    xNew = _axis.x * cosZ - _axis.y * sinZ;
    yNew = _axis.x * sinZ + _axis.y * cosZ;
    _axis.x = xNew;
    _axis.y = yNew;
    _axis = _axis.normalized();
}

std::shared_ptr<RayTracer::IMaterial> RayTracer::Cylinder::getMaterial() const
{
    return _material;
}

void RayTracer::Cylinder::setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material)
{
    _material = material;
}

const RayTracer::Point3D &RayTracer::Cylinder::getBase() const
{
    return _base;
}

const RayTracer::Vector3D &RayTracer::Cylinder::getAxis() const
{
    return _axis;
}

float RayTracer::Cylinder::getRadius() const
{
    return _radius;
}

float RayTracer::Cylinder::getHeight() const
{
    return _height;
}

const RayTracer::Color &RayTracer::Cylinder::getColor() const
{
    return _color;
}