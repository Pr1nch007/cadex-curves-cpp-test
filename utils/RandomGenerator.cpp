#include "RandomGenerator.h"

#include <ctime>
#include <string>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

void generateRandomCurves(std::vector<std::shared_ptr<Curve>>& curves, size_t numAdditional) {
    std::mt19937 gen(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_real_distribution<double> dist_center(-10.0, 10.0);
    std::uniform_real_distribution<double> dist_radius(0.1, 10.0);
    std::uniform_real_distribution<double> dist_step(-10.0, 10.0);
    std::uniform_int_distribution<int> dist_type(0, 2);  // 0=Circle, 1=Ellipse, 2=Helix

    uint64_t id_counter = 1;

    Point center = {dist_center(gen), dist_center(gen), dist_center(gen)};
    curves.push_back(std::make_shared<Circle>(id_counter++, "Random Circle #1", center, dist_radius(gen)));

    center = {dist_center(gen), dist_center(gen), dist_center(gen)};
    curves.push_back(std::make_shared<Ellipse>(id_counter++, "Random Ellipse #1", center, dist_radius(gen), dist_radius(gen)));

    center = {dist_center(gen), dist_center(gen), dist_center(gen)};
    curves.push_back(std::make_shared<Helix>(id_counter++, "Random Helix #1", center, dist_radius(gen), dist_step(gen)));

    for (size_t i = 0; i < numAdditional; ++i) {
        center = {dist_center(gen), dist_center(gen), dist_center(gen)};
        int type = dist_type(gen);
        std::string name = "Random ";
        if (type == 0) {
            name += "Circle #" + std::to_string(i + 2);
            curves.push_back(std::make_shared<Circle>(id_counter++, name, center, dist_radius(gen)));
        } else if (type == 1) {
            name += "Ellipse #" + std::to_string(i + 2);
            curves.push_back(std::make_shared<Ellipse>(id_counter++, name, center, dist_radius(gen), dist_radius(gen)));
        } else {
            name += "Helix #" + std::to_string(i + 2);
            curves.push_back(std::make_shared<Helix>(id_counter++, name, center, dist_radius(gen), dist_step(gen)));
        }
    }
}