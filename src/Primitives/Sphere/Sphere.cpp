/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere(const Point3D &center, double radius, Color color)
    : _center(center), _radius(radius), _color(color) {}

bool RayTracer::Sphere::hits(const Ray &ray) const
{
    Vector3D oc = ray.getOrigin() - _center;
    double a = ray.getDirection().length() * ray.getDirection().length();
    double b = 2.0 * (oc.dot(ray.getDirection()));
    double c = oc.length() * oc.length() - _radius * _radius;
    double discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}