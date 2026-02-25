#include "Helix.h"
#include "constants.h"
#include <cmath>

Helix::Helix(uint64_t id, std::string name, Point center, double radius, double step)
    : Curve(id, std::move(name), center), radius_(radius), step_(step) {}

Point Helix::getPoint(double t) const {
    Point p;
    p.x = center_.x + radius_ * std::cos(t);
    p.y = center_.y + radius_ * std::sin(t);
    p.z = center_.z + (step_ / (2.0 * cadex::PI)) * t;
    return p;
}

Vector Helix::getDerivative(double t) const {
    Vector v;
    v.x = -radius_ * std::sin(t);
    v.y = radius_ * std::cos(t);
    v.z = step_ / (2.0 * cadex::PI);
    return v;
}