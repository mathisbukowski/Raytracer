/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef FLATCOLORMATERIALFACTORY_HPP
#define FLATCOLORMATERIALFACTORY_HPP

#include "IMaterialFactory.hpp"
#include "../Materials/IMaterial.hpp"

namespace RayTracer {
    class FlatColorMaterialFactory : public IMaterialFactory {
        std::shared_ptr<IMaterial> createMaterial(const libconfig::Setting &setting) override;
    };
}



#endif //FLATCOLORMATERIALFACTORY_HPP
