#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "Parser.h"
#include "Printer.h"
#include "Curve.h"
#include "Circle.h"
#include "constants.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: curves_app <input_file_path>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::vector<std::shared_ptr<Curve>> allCurves;

    if (!parseFile(path, allCurves)) {
        return 1;
    }

    double t = cadex::PI_4;

    std::cout << "All curves at t = π/4:\n";
    printAllCurvesInfo(allCurves, t);

    std::vector<std::shared_ptr<Circle>> circles;

    for (const auto& curve : allCurves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }

    // Сортировка по радиусу (по возрастанию)
    std::sort(circles.begin(), circles.end(),
              [](const auto& a, const auto& b) {
                  return a->getRadius() < b->getRadius();
              });

    printCirclesAndSum(circles);

    return 0;
}