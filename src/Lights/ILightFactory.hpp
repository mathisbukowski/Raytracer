/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef ILIGHTFACTORY_HPP
#define ILIGHTFACTORY_HPP

#include "ILight.hpp"
#include <memory>
#include <libconfig.h++>


namespace RayTracer {
    class ILightFactory {
    public:
        virtual ~ILightFactory() = default;
        virtual std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const = 0;

        static std::shared_ptr<ILightFactory> getFactory(const std::string& type);
    };
}

#endif //ILIGHTFACTORY_HPP
