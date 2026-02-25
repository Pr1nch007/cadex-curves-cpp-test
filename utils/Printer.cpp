#include "Printer.h"

#include <iostream>
#include <iomanip>
#include <numeric>

void printAllCurvesInfo(const std::vector<std::shared_ptr<Curve>>& curves, double t) {
    std::cout << std::fixed << std::setprecision(6);

    for (const auto& curve : curves) {
        std::cout << "ID: " << curve->getId()
                  << "  Name: \"" << curve->getName() << "\"" << std::endl;

        Point p = curve->getPoint(t);
        std::cout << "  Point:     (" 
                  << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;

        Vector v = curve->getDerivative(t);
        std::cout << "  Derivative: (" 
                  << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;

        std::cout << std::endl;
    }
}

void printCirclesAndSum(const std::vector<std::shared_ptr<Circle>>& circles) {
    if (circles.empty()) {
        std::cout << "No valid circles found.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\n=== Circles (sorted by radius) ===\n";

    double sum_r = 0.0;

    for (const auto& c : circles) {
        double r = c->getRadius();

        std::cout << "ID: " << c->getId()
                  << "  Name: \"" << c->getName() << "\""
                  << "  Radius: " << r << std::endl;

        sum_r += r;
    }

    std::cout << "\nTotal sum of radii: " << sum_r << std::endl;
}