/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef CYLINDERFACTORY_HPP
#define CYLINDERFACTORY_HPP

#include "PrimitiveFactory.hpp"

namespace RayTracer {
    /**
    * @class CylinderFactory
    * Factory for creating cylinder primitives.
    */
    class CylinderFactory : public IPrimitiveFactory {
    public:
        std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) override;
    };
}



#endif //CYLINDERFACTORY_HPP
