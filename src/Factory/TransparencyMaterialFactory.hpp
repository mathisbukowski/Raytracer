/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef TRANSPARENCYMATERIALFACTORY_HPP
#define TRANSPARENCYMATERIALFACTORY_HPP

#include "IMaterialFactory.hpp"

namespace RayTracer {
    class TransparencyMaterialFactory : public IMaterialFactory {
        std::shared_ptr<IMaterial> createMaterial(const libconfig::Setting& setting) override;
    };
}



#endif //TRANSPARENCYMATERIALFACTORY_HPP
