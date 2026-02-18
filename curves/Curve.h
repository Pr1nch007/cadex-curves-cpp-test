#pragma once

#include <cstdint>
#include <string>

struct Point {
    double x = 0.0, y = 0.0, z = 0.0;
};

using Vector = Point;  // семантический алиас

class Curve {
public:
    Curve(uint64_t id, std::string name, Point center)
        : id_(id), name_(std::move(name)), center_(center) {}

    virtual ~Curve() = default;

    virtual Point getPoint(double t) const = 0;
    virtual Vector getDerivative(double t) const = 0;
private:
    uint64_t id_;
    std::string name_;
    Point center_;
};