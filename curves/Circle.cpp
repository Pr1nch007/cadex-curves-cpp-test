#include "Circle.h"
#include <cmath>

Circle::Circle(uint64_t id, std::string name, Point center, double radius)
    : Curve(id, std::move(name), center), radius_(radius) {}

Point Circle::getPoint(double t) const {
    Point p;
    p.x = center_.x + radius_ * std::cos(t);
    p.y = center_.y + radius_ * std::sin(t);
    p.z = center_.z;
    return p;
}

Vector Circle::getDerivative(double t) const {
    Vector v;
    v.x = -radius_ * std::sin(t);
    v.y = radius_ * std::cos(t);
    v.z = 0.0;
    return v;
}