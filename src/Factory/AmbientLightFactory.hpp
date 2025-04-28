/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef AMBIENTLIGHTFACTORY_HPP
#define AMBIENTLIGHTFACTORY_HPP

#include "../Lights/ILight.hpp"
#include "ILightFactory.hpp"


namespace RayTracer {
    /**
     * @class AmbientLightFactory
     * Factory class for creating ambient light sources.
     */
    class AmbientLightFactory : public ILightFactory {
    public:
    /**
     * Creates an ambient light source based on the provided configuration.
     * @param setting The configuration setting for the light source.
     * @return A shared pointer to the created ambient light source.
     */
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}



#endif //AMBIENTLIGHTFACTORY_HPP
