/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** PPMWriter
*/

#ifndef PPMWRITER_HPP
#define PPMWRITER_HPP

#include <string>
#include <vector>
#include "../Utils/Color.hpp"

namespace RayTracer {

class PPMWriter {
public:
    static void write(const std::string& filename, int width, int height, const std::vector<Color>& framebuffer);
};

}

#endif //PPMWRITER_HPP
