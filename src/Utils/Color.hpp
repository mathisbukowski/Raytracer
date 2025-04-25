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

class Color {
public:
    float r, g, b;

    Color();
    Color(float r, float g, float b);

    void clamp();

    Color operator*(float scalar) const;
    Color& operator+=(const Color& other);
    Color operator+(const Color& other) const;

    friend Color operator*(float scalar, const Color& color);
    friend std::ostream& operator<<(std::ostream& os, const Color& c);

    int red() const;
    int green() const;
    int blue() const;

private:
    int toInt(float value) const;
};

}

#endif // COLOR_HPP
