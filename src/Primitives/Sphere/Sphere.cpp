/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere.cpp
*/

#include <valarray>
#include "Sphere.hpp"

RayTracer::Sphere::Sphere(const Point3D &center, double radius, Color color, const std::shared_ptr<IMaterial> &material)
    : _center(center), _radius(radius), _color(color), _material(material) {}

bool RayTracer::Sphere::intersect(const RayTracer::Ray &ray, float &t, RayTracer::Vector3D &normal) const
{
    Vector3D oc = ray.getOrigin() - _center;
    double a = ray.getDirection().length() * ray.getDirection().length();
    double b = 2.0 * (oc.dot(ray.getDirection()));
    double c = oc.length() * oc.length() - _radius * _radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return false;
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    if (t1 > 0.001f && (t2 < 0.001f || t1 < t2))
        t = t1;
    else if (t2 > 0.001f)
        t = t2;
    else
        return false;
    Point3D intersectionPoint = ray.getOrigin() + ray.getDirection() * t;
    normal = (intersectionPoint - _center);
    return true;
}

const RayTracer::Point3D &RayTracer::Sphere::getCenter() const
{
    return _center;
}

const RayTracer::Color &RayTracer::Sphere::getColor() const
{
    return _color;
}

double RayTracer::Sphere::getRadius() const
{
    return _radius;
}

void RayTracer::Sphere::translate(const RayTracer::Vector3D &translation)
{
    _center = _center + translation;
}

void RayTracer::Sphere::rotate(const RayTracer::Vector3D &rotation)
{
    (void)rotation;
}

std::shared_ptr<RayTracer::IMaterial> RayTracer::Sphere::getMaterial() const
{
    return _material;
}

void RayTracer::Sphere::setMaterial(const std::shared_ptr<RayTracer::IMaterial> &material)
{
    _material = material;
}
