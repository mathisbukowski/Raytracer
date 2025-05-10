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
    /**
     * @class TransparencyMaterialFactory
     * Factory class for creating TransparencyMaterial instances.
     */
    class TransparencyMaterialFactory : public IMaterialFactory {
        /**
         * Creates a new TransparencyMaterial instance based on the provided configuration.
         * @param setting The configuration setting for the material.
         * @return A shared pointer to the created TransparencyMaterial instance.
         */
        std::shared_ptr<IMaterial> createMaterial(const libconfig::Setting &setting) override;
    };
}



#endif //TRANSPARENCYMATERIALFACTORY_HPP
