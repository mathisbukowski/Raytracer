/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
#define PRIMITIVEFACTORY_HPP_

#include <memory>
#include <string>
#include "../Primitives/IPrimitive.hpp"
#include "../Utils/Color.hpp"
#include <libconfig.h++>

namespace RayTracer {
    /**
     * @class IPrimitiveFactory
     * Interface for primitive factory implementations.
     */
    class IPrimitiveFactory {
    public:
        virtual ~IPrimitiveFactory() = default;
        virtual std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) = 0;
        static std::shared_ptr<IPrimitiveFactory> getFactory(const std::string& type);
    };
}

#endif // PRIMITIVEFACTORY_HPP_
