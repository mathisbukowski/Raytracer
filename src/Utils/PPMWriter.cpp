/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** PPMWriter
*/

#include "PPMWriter.hpp"
#include <fstream>
#include <iostream>

namespace RayTracer {

void PPMWriter::write(const std::string& filename, int width, int height, const std::vector<Color>& framebuffer) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    file << "P3\n";
    file << width << " " << height << "\n";
    file << "255\n";

    for (int i = 0; i < height * width; ++i) {
        Color pixel = framebuffer[i];
        pixel.clamp();
        file << pixel.red() << " " << pixel.green() << " " << pixel.blue() << "\n";
    }

    file.close();
    std::cout << "Image written to " << filename << std::endl;
}

}
