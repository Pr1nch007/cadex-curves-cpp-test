#include "Parser.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

bool isValidCircle(double radius) {
    return radius > 0.0;
}

bool isValidEllipse(double rx, double ry) {
    return rx > 0.0 && ry > 0.0;
}

bool isValidHelix(double radius) {
    return radius > 0.0;
}

bool parseCurveLine(const std::string& line, std::shared_ptr<Curve>& outCurve) {
    std::istringstream iss(line);
    char type;
    uint64_t id;
    std::string name;
    Point center;
    double param1, param2;

    if (!(iss >> type >> id >> std::quoted(name) >> center.x >> center.y >> center.z)) {
        std::cerr << "Warning: Invalid line format: " << line << std::endl;
        return false;
    }

    // Создание объекта в зависимости от типа
    switch (type) {
        case 'C': {
            if (!(iss >> param1) || !iss.eof()) {
                std::cerr << "Warning: Invalid parameters for Circle: " << line << std::endl;
                return false;
            }
            if (!isValidCircle(param1)) {
                std::cerr << "Warning: Invalid Circle (radius <= 0): " << line << std::endl;
                return false;
            }
            outCurve = std::make_shared<Circle>(id, name, center, param1);
            return true;
        }
        case 'E': {
            if (!(iss >> param1 >> param2) || !iss.eof()) {
                std::cerr << "Warning: Invalid parameters for Ellipse: " << line << std::endl;
                return false;
            }
            if (!isValidEllipse(param1, param2)) {
                std::cerr << "Warning: Invalid Ellipse (rx/ry <= 0): " << line << std::endl;
                return false;
            }
            outCurve = std::make_shared<Ellipse>(id, name, center, param1, param2);
            return true;
        }
        case 'H': {
            if (!(iss >> param1 >> param2) || !iss.eof()) {
                std::cerr << "Warning: Invalid parameters for Helix: " << line << std::endl;
                return false;
            }
            if (!isValidHelix(param1)) {
                std::cerr << "Warning: Invalid Helix (radius <= 0): " << line << std::endl;
                return false;
            }
            outCurve = std::make_shared<Helix>(id, name, center, param1, param2);
            return true;
        }
        default:
            std::cerr << "Warning: Unknown curve type '" << type << "': " << line << std::endl;
            return false;
    }
}

bool parseFile(const std::string& path, std::vector<std::shared_ptr<Curve>>& curves) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return false;
    }

    int numCurves;
    if (!(file >> numCurves)) {
        std::cerr << "Error: Failed to read number of curves" << std::endl;
        return false;
    }

    std::string dummyLine;
    std::getline(file, dummyLine);

    for (int i = 0; i < numCurves; ++i) {
        std::string line;
        if (!std::getline(file, line)) {
            std::cerr << "Warning: Unexpected end of file, expected " << numCurves << " curves" << std::endl;
            break;
        }

        std::shared_ptr<Curve> curve;
        if (parseCurveLine(line, curve)) {
            curves.push_back(curve);
        }
    }

    return true;
}



