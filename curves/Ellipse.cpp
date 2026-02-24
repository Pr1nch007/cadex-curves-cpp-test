#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(uint64_t id, std::string name, Point center, double rx, double ry)
    : Curve(id, std::move(name), center), rx_(rx), ry_(ry) {}

Point Ellipse::getPoint(double t) const {
    Point p;
    p.x = center_.x + rx_ * std::cos(t);
    p.y = center_.y + ry_ * std::sin(t);
    p.z = center_.z;
    return p;
}

Vector Ellipse::getDerivative(double t) const {
    Vector v;
    v.x = -rx_ * std::sin(t);
    v.y = ry_ * std::cos(t);
    v.z = 0.0;
    return v;
}