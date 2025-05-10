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
    /**
     * @class FlatColorMaterialFactory
     * Factory class for creating FlatColorMaterial instances.
     */
    class FlatColorMaterialFactory : public IMaterialFactory {
        /**
         * Creates a new FlatColorMaterial instance based on the provided configuration.
         * @param setting The configuration setting for the material.
         * @return A shared pointer to the created FlatColorMaterial instance.
         */
        std::shared_ptr<IMaterial> createMaterial(const libconfig::Setting &setting) override;
    };
}



#endif //FLATCOLORMATERIALFACTORY_HPP
