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
        /**
         * Virtual destructor for the IPrimitiveFactory interface.
         */
        virtual ~IPrimitiveFactory() = default;
        /**
         * Creates a primitive based on the provided configuration.
         * @param settings The configuration setting for the primitive.
         * @return A shared pointer to the created
         */
        virtual std::shared_ptr<IPrimitive> createPrimitive(const libconfig::Setting& settings) = 0;
        /**
         * Factory method to get the appropriate primitive factory based on the type.
         * @param type The type of primitive to create.
         * @return A shared pointer to the appropriate primitive factory.
         */
        static std::shared_ptr<IPrimitiveFactory> getFactory(const std::string& type);
    };
}

#endif // PRIMITIVEFACTORY_HPP_
