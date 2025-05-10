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

    /**
     * @class PPMWriter
     * Utility class for writing PPM (Portable Pixmap) files.
     */
    class PPMWriter {
        public:
            /**
             * Writes a PPM file with the given width, height, and framebuffer data.
             * @param filename The name of the output PPM file.
             * @param width The width of the image.
             * @param height The height of the image.
             * @param framebuffer The pixel data for the image.
             */
            static void write(const std::string& filename, int width, int height, const std::vector<Color>& framebuffer);
    };

}

#endif //PPMWRITER_HPP
