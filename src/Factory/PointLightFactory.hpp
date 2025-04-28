/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef POINTLIGHTFACTORY_HPP
#define POINTLIGHTFACTORY_HPP

#include "../Lights/ILight.hpp"
#include "../Lights/PointLight.hpp"
#include "ILightFactory.hpp"
#include <memory>

namespace RayTracer {
    /**
     * @class PointLightFactory
     * Factory class for creating point light sources.
     */
    class PointLightFactory : public ILightFactory {
    public:
        /**
         * Creates a point light source based on the provided configuration.
         * @param setting The configuration setting for the light source.
         * @return A shared pointer to the created point light source.
         */
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}



#endif //POINTLIGHTFACTORY_HPP
