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
        /**
        * Creates a cylinder primitive based on the provided configuration.
        * @param settings The configuration setting for the cylinder.
        * @return A shared pointer to the created cylinder primitive.
        */
        std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) override;
    };
}



#endif //CYLINDERFACTORY_HPP
