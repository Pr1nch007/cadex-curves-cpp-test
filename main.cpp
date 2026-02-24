/*#include <iostream>
#include <vector>
#include <memory>

#include "Curve.h"

int main(int argc, char* argv[]) {
    std::cout << "CAD Exchanger curves test\n";
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    std::cout << "File to parse: " << argv[1] << "\n";
    return 0;
}*/


/*#include <iostream>
#include <memory>
#include <iomanip>  // для std::setprecision

#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

int main() {
    const double PI = std::acos(-1.0);
    double t = PI / 4.0;  // π/4 ≈ 0.785398

    Point center = {0.0, 0.0, 0.0};

    // Тест Circle (radius=1)
    auto circle = std::make_shared<Circle>(1, "test_circle", center, 1.0);
    auto p_circle = circle->getPoint(t);
    auto d_circle = circle->getDerivative(t);
    std::cout << std::setprecision(6) << "Circle Point: (" << p_circle.x << ", " << p_circle.y << ", " << p_circle.z << ")" << std::endl;
    std::cout << "Circle Derivative: (" << d_circle.x << ", " << d_circle.y << ", " << d_circle.z << ")" << std::endl;

    // Тест Ellipse (rx=2, ry=3)
    auto ellipse = std::make_shared<Ellipse>(2, "test_ellipse", center, 2.0, 3.0);
    auto p_ellipse = ellipse->getPoint(t);
    auto d_ellipse = ellipse->getDerivative(t);
    std::cout << "Ellipse Point: (" << p_ellipse.x << ", " << p_ellipse.y << ", " << p_ellipse.z << ")" << std::endl;
    std::cout << "Ellipse Derivative: (" << d_ellipse.x << ", " << d_ellipse.y << ", " << d_ellipse.z << ")" << std::endl;

    // Тест Helix (radius=2, step=6.283185 ≈ 2π, чтобы подъём на оборот = 1)
    auto helix = std::make_shared<Helix>(3, "test_helix", center, 2.0, 6.283185);
    auto p_helix = helix->getPoint(t);
    auto d_helix = helix->getDerivative(t);
    std::cout << "Helix Point: (" << p_helix.x << ", " << p_helix.y << ", " << p_helix.z << ")" << std::endl;
    std::cout << "Helix Derivative: (" << d_helix.x << ", " << d_helix.y << ", " << d_helix.z << ")" << std::endl;

    return 0;
}*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

#include "Curve.h"
#include "Helix.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        std::cerr << "Example:\n";
        std::cerr << "  " << argv[0] << " curves_to_check.txt\n";
        std::cerr << "  " << argv[0] << " additional_curves_1.txt\n";
        return 1;
    }

    const std::string filename = argv[1];

    std::vector<std::shared_ptr<Curve>> curves;

    if (!parseFile(filename, curves))
    {
        std::cerr << "Failed to parse file: " << filename << "\n";
        return 2;
    }

    std::cout << "\nParsed " << curves.size() << " valid curves from " << filename << "\n\n";

    const double PI = 3.14159265358979323846;
    const double t = PI / 4.0;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "t = π/4 ≈ " << t << "\n";
    std::cout << "────────────────────────────────────────────────────────────\n";

    for (const auto& curve : curves)
    {
        Point  p = curve->getPoint(t);
        Vector v = curve->getDerivative(t);

        std::cout << "ID   : " << curve->id_ << "\n";
        std::cout << "Name : " << curve->name_ << "\n";

        std::cout << "Point       : "
                  << "(" << p.x << ", " << p.y << ", " << p.z << ")\n";

        std::cout << "Derivative  : "
                  << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";

        std::cout << "────────────────────────────────────────────────────────────\n";
    }

    size_t n_circle = 0, n_ellipse = 0, n_helix = 0;

    for (const auto& c : curves)
    {
        if (std::dynamic_pointer_cast<Circle>(c))  ++n_circle;
        else if (std::dynamic_pointer_cast<Ellipse>(c)) ++n_ellipse;
        else if (std::dynamic_pointer_cast<Helix>(c))   ++n_helix;
    }

    std::cout << "\nSummary:\n";
    std::cout << "  Circles  : " << n_circle  << "\n";
    std::cout << "  Ellipses : " << n_ellipse << "\n";
    std::cout << "  Helixes  : " << n_helix   << "\n";
    std::cout << "  Total    : " << curves.size() << "\n";

    return 0;
}