/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cone.cpp
*/

#include "Cone.hpp"

RayTracer::Cone::Cone(const Point3D &apex, const Vector3D &axis, float baseRadius, float height,
                      Color color, const std::shared_ptr<IMaterial> &material)
{
    _apex = apex;
    _axis = axis.normalized();
    _baseRadius = baseRadius;
    _height = height;
    _color = color;
    _material = material;

}

bool RayTracer::Cone::intersect(const RayTracer::Ray &ray, float &t, RayTracer::Vector3D &normal) const
{
    Vector3D rayDir = ray.getDirection();
    Point3D rayOrigin = ray.getOrigin();
    float halfAngle = this->getHalfAngle();
    float cosHalfAngleSq = cos(halfAngle) * cos(halfAngle);
    Vector3D originToApex = rayOrigin - _apex;
    float dotDirAxis = rayDir.dot(_axis);
    float dotOrgAxis = originToApex.dot(_axis);
    float a = dotDirAxis * dotDirAxis - cosHalfAngleSq * rayDir.dot(rayDir);
    float b = 2.0f * (dotDirAxis * dotOrgAxis - cosHalfAngleSq * rayDir.dot(originToApex));
    float c = dotOrgAxis * dotOrgAxis - cosHalfAngleSq * originToApex.dot(originToApex);
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return false;
    float t1 = (-b - sqrt(discriminant)) / (2.0f * a);
    float t2 = (-b + sqrt(discriminant)) / (2.0f * a);
    float t_cone = -1;
    if (t1 > 0.001f) {
        Point3D hitPoint = rayOrigin + rayDir * t1;
        float hitHeight = (hitPoint - _apex).dot(_axis);
        if (hitHeight >= 0 && hitHeight <= _height) {
            t_cone = t1;
        }
    }
    if (t2 > 0.001f) {
        Point3D hitPoint = rayOrigin + rayDir * t2;
        float hitHeight = (hitPoint - _apex).dot(_axis);
        if (hitHeight >= 0 && hitHeight <= _height) {
            if (t_cone < 0 || t2 < t_cone) {
                t_cone = t2;
            }
        }
    }
    bool hit_cone_side = (t_cone > 0);
    bool hit_base = false;
    float t_base = -1;
    Point3D baseCenter = this->getBaseCenter();
    float denom = rayDir.dot(_axis);
    if (fabs(denom) > 0.001f) {
        float t_base_plane = (baseCenter - rayOrigin).dot(_axis) / denom;
        if (t_base_plane > 0.001f) {
            Point3D hitPoint = rayOrigin + rayDir * t_base_plane;
            Vector3D baseTohit = hitPoint - baseCenter;
            if (baseTohit.dot(baseTohit) <= _baseRadius * _baseRadius) {
                t_base = t_base_plane;
                hit_base = true;
            }
        }
    }
    if (hit_cone_side && (!hit_base || t_cone < t_base)) {
        t = t_cone;
        Point3D hitPoint = rayOrigin + rayDir * t;
        Vector3D apexToHit = hitPoint - _apex;
        float projOnAxis = apexToHit.dot(_axis);
        Vector3D projVec = _axis * projOnAxis;
        normal = (apexToHit - projVec * (1 + _baseRadius / _height)).normalized();
    } else if (hit_base) {
        t = t_base;
        normal = -_axis;
    } else {
        return false;
    }
    return true;
}

void RayTracer::Cone::translate(const RayTracer::Vector3D &translation)
{
    _apex = _apex + translation;
}

void RayTracer::Cone::rotate(const RayTracer::Vector3D &rotation)
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

std::shared_ptr<RayTracer::IMaterial> RayTracer::Cone::getMaterial() const
{
    return _material;
}

void RayTracer::Cone::setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material)
{
    _material = material;
}

const RayTracer::Point3D &RayTracer::Cone::getApex() const
{
    return _apex;
}

const RayTracer::Vector3D &RayTracer::Cone::getAxis() const
{
    return _axis;
}

float RayTracer::Cone::getBaseRadius() const
{
    return _baseRadius;
}

float RayTracer::Cone::getHeight() const
{
    return _height;
}

const RayTracer::Color &RayTracer::Cone::getColor() const
{
    return _color;
}

RayTracer::Point3D RayTracer::Cone::getBaseCenter() const
{
    return _apex + _axis * _height;
}

float RayTracer::Cone::getHalfAngle() const
{
    return atan(_baseRadius / _height);
}