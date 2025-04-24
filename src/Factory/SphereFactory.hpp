/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef SPHEREFACTORY_HPP
#define SPHEREFACTORY_HPP


#include "PrimitiveFactory.hpp"


namespace RayTracer {
    /**
     * @class SphereFactory
     * Factory for creating sphere primitives.
     */
    class SphereFactory : public IPrimitiveFactory {
    public:
        std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) override;
    };
}


#endif //SPHEREFACTORY_HPP
