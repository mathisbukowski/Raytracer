/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef DIRECTIONALLIGHTFACTORY_HPP
#define DIRECTIONALLIGHTFACTORY_HPP

#include "../Lights/ILight.hpp"
#include "ILightFactory.hpp"
#include <memory>
#include <libconfig.h++>
#include "../Lights/DirectionalLight.hpp"

namespace RayTracer {
    /**
     * @class DirectionalLightFactory
     * Factory class for creating directional light sources.
     */
    class DirectionalLightFactory : public ILightFactory {
    public:
        /**
         * Creates a directional light source based on the provided configuration.
         * @param setting The configuration setting for the light source.
         * @return A shared pointer to the created directional light source.
         */
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}


#endif //DIRECTIONALLIGHTFACTORY_HPP
