/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef IMATERIALFACTORY_HPP
#define IMATERIALFACTORY_HPP

#include <memory>
#include <string>
#include "../Materials/IMaterial.hpp"
#include <libconfig.h++>

namespace RayTracer {
    /**
     * @class IMaterialFactory
     * Interface to create MaterialFactory
     */
    class IMaterialFactory {
        public:
        /**
         * Destructor of factory
         */
        virtual ~IMaterialFactory() = default;
        /**
         * Create a new material
         * @param setting
         * @return shared_ptr of new material
         */
        virtual std::shared_ptr<IMaterial> createMaterial(const libconfig::Setting &setting) = 0;
        /**
         * Gets the factory with a type
         * @param type type of the factory
         * @return shared ptr of the factory
         */
        static std::shared_ptr<IMaterialFactory> getFactory(const std::string &type);
    };
};


#endif //IMATERIALFACTORY_HPP
