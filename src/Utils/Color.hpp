/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Color
*/

#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

namespace RayTracer {

    /**
     * @class Color
     * Represents a color in RGB format.
     */
    class Color {
        public:
            float r, g, b; ///< The red, green, and blue components of the color.

            /**
             * Default constructor for Color.
             * Initializes the color to (0, 0, 0).
             */
            Color();
            /**
             * Constructs a Color with specified red, green, and blue components.
             * @param r float The red component.
             * @param g float The green component.
             * @param b float The blue component.
             */
            Color(float r, float g, float b);

            /**
             * Clamps the color components to the range [0, 1].
             */
            void clamp();

            /**
             * Multiplies the color by a scalar.
             * @param scalar float The scalar value.
             * @return The resulting color after multiplication.
             */
            Color operator*(float scalar) const;
            /**
             * Adds another color to the current color.
             * @param other const Color & The color to add.
             * @return A reference to the current color after addition.
             */
            Color& operator+=(const Color& other);
            /**
             * Adds another color to the current color.
             * @param other const Color & The color to add.
             * @return The resulting color after addition.
             */
            Color operator+(const Color& other) const;

            /**
             * Multiplies a scalar with a color.
             * @param scalar float The scalar value.
             * @param color const Color & The color to multiply.
             * @return The resulting color after multiplication.
             */
            friend Color operator*(float scalar, const Color& color);
            /**
             * Outputs the color to an output stream.
             * @param os std::ostream & The output stream.
             * @param c const Color & The color to output.
             * @return The output stream after writing the color.
             */
            friend std::ostream& operator<<(std::ostream& os, const Color& c);

            /**
             * Converts the color components to integers in the range [0, 255].
             * @return The red component as an integer.
             */
            int red() const;
            /**
             * Converts the color components to integers in the range [0, 255].
             * @return The green component as an integer.
             */
            int green() const;
            /**
             * Converts the color components to integers in the range [0, 255].
             * @return The blue component as an integer.
             */
            int blue() const;

            Color operator/(float scalar) const;

        private:
            /**
             * Converts a float value to an integer in the range [0, 255].
             * @param value float The value to convert.
             * @return The converted integer value.
             */
            int toInt(float value) const;
};

}

#endif // COLOR_HPP
