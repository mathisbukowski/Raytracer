/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef CONEFACTORY_HPP
#define CONEFACTORY_HPP

#include "PrimitiveFactory.hpp"

namespace RayTracer {
    /**
     * @class ConeFactory
     * Factory for creating cone primitives.
     */
    class ConeFactory : public IPrimitiveFactory {
    public:
        std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) override;
    };
}



#endif //CONEFACTORY_HPP
