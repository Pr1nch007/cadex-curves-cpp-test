#pragma once
#include "Curve.h"

class Circle : public Curve {
public:
    Circle(uint64_t id, std::string name, Point center, double radius);
    Point getPoint(double t) const override;
    Vector getDerivative(double t) const override;
private:
    double radius_;
};