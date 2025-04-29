/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere(const Point3D &center, double radius, Color color)
    : _center(center), _radius(radius), _color(color) {}

bool RayTracer::Sphere::intersect(const RayTracer::Ray &ray, float &t, RayTracer::Vector3D &normal) const
{
    Vector3D oc = ray.getOrigin() - _center;
    double a = ray.getDirection().length() * ray.getDirection().length();
    double b = 2.0 * (oc.dot(ray.getDirection()));
    double c = oc.length() * oc.length() - _radius * _radius;
    double discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
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

std::shared_ptr<IMaterial> RayTracer::Sphere::getMaterial() const
{
    return _material;
}

void RayTracer::Sphere::setMaterial(const std::shared_ptr<IMaterial> &material)
{
    _material = material;
}
