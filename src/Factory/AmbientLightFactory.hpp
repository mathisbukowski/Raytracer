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
    class AmbientLightFactory : public ILightFactory {
    public:
        std::shared_ptr<ILight> createLight(const libconfig::Setting& setting) const override;
    };
}



#endif //AMBIENTLIGHTFACTORY_HPP
