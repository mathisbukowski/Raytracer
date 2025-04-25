/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Color
*/

#include "Color.hpp"
#include <algorithm>

namespace RayTracer {

Color::Color() : r(0), g(0), b(0) {}

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

void Color::clamp() {
    r = std::min(1.0f, std::max(0.0f, r));
    g = std::min(1.0f, std::max(0.0f, g));
    b = std::min(1.0f, std::max(0.0f, b));
}

Color Color::operator*(float scalar) const {
    return Color(r * scalar, g * scalar, b * scalar);
}

Color& Color::operator+=(const Color& other) {
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
}

Color Color::operator+(const Color& other) const {
    return Color(r + other.r, g + other.g, b + other.b);
}

Color operator*(float scalar, const Color& color) {
    return color * scalar;
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    return os << "Color(" << c.r << ", " << c.g << ", " << c.b << ")";
}

int Color::toInt(float value) const {
    return static_cast<int>(std::min(255.0f, std::max(0.0f, value * 255.0f)));
}

int Color::red() const {
    return toInt(r);
}

int Color::green() const {
    return toInt(g);
}

int Color::blue() const {
    return toInt(b);
}

}
