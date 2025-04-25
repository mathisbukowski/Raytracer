/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef ILIGHTFACTORY_HPP
#define ILIGHTFACTORY_HPP

#include "../Lights/ILight.hpp"
#include <memory>
#include <libconfig.h++>


namespace RayTracer {
    /**
     * @class ILightFactory
     * Interface for creating light sources.
     */
    class ILightFactory {
    public:
        /**
         * Creates a light source based on the provided configuration.
         * @param setting The configuration setting for the light source.
         * @return A shared pointer to the created light source.
         */
        virtual ~ILightFactory() = default;
        /**
         * Creates a light source based on the provided configuration.
         * @param setting The configuration setting for the light source.
         * @return A shared pointer to the created light source.
         */
        virtual std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const = 0;
        /**
         * Factory method to get the appropriate light factory based on the type.
         * @param type The type of light source to create.
         * @return A shared pointer to the appropriate light factory.
         */
        static std::shared_ptr<ILightFactory> getFactory(const std::string& type);
    };
}

#endif //ILIGHTFACTORY_HPP
