#pragma once

#include <memory>
#include <vector>
#include <random>

#include "Curve.h"

// Генерирует случайные кривые (ensure all types, positive radii)
void generateRandomCurves(std::vector<std::shared_ptr<Curve>>& curves, size_t numAdditional = 10);