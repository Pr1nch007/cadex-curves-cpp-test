#pragma once
#include "Curve.h"

class Ellipse : public Curve {
public:
    Ellipse(uint64_t id, std::string name, Point center, double rx, double ry);
    Point getPoint(double t) const override;
    Vector getDerivative(double t) const override;
private:
    double rx_, ry_;
};