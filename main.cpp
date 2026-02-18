#include <iostream>
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
}