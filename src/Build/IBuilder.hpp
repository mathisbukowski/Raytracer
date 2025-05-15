/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 05
*/

#ifndef IBUILDER_HPP
#define IBUILDER_HPP

namespace RayTracer {
    template<class BuilderType>
    class IBuilder {
        public:
        virtual ~IBuilder() = default;
        virtual BuilderType build() = 0;
    };
}

#endif //IBUILDER_HPP
