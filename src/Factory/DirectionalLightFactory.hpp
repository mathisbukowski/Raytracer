/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef DIRECTIONALLIGHTFACTORY_HPP
#define DIRECTIONALLIGHTFACTORY_HPP

#include "../Lights/ILight.hpp"
#include "../Lights/ILightFactory.hpp"
#include <memory>
#include <libconfig.h++>
#include "../Lights/DirectionalLight.hpp"

namespace RayTracer {
    class DirectionalLightFactory : public ILightFactory {
    public:
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}


#endif //DIRECTIONALLIGHTFACTORY_HPP
