#pragma once
#include "Curve.h"

class Helix : public Curve {
public:
    Ellipse(uint64_t id, std::string name, Point center, double radius, double step);
    Point getPoint(double t) const override;
    Vector getDerivative(double t) const override;
private:
    double radius_, step_;
};