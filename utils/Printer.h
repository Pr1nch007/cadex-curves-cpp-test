#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Curve.h"

//Выводит информацию обо всех кривых в контейнере
void printAllCurvesInfo(const std::vector<std::shared_ptr<Curve>>& curves, double t);

//Выводит информацию только о кругах (после сортировки)
void printCirclesAndSum(const std::vector<std::shared_ptr<Circle>>& circles);