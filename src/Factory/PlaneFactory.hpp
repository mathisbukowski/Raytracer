/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef PLANEFACTORY_HPP
#define PLANEFACTORY_HPP

#include "PrimitiveFactory.hpp"

namespace RayTracer {
    /**
     * @class PlaneFactory
     * Factory for creating plane primitives.
     */
    class PlaneFactory : public IPrimitiveFactory {
    public:
        /**
         * Creates a plane primitive based on the provided configuration.
         * @param settings The configuration setting for the plane.
         * @return A shared pointer to the created plane primitive.
         */
        std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) override;
    };
}

#endif //PLANEFACTORY_HPP
