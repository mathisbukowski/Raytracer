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
    class PointLightFactory : public ILightFactory {
    public:
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}



#endif //POINTLIGHTFACTORY_HPP
