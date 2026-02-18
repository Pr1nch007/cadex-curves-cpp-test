#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Curve.h"

// Парсит входной файл и заполняет контейнер кривыми
// Возвращает true при успешном чтении (даже если некоторые кривые пропущены из-за некорректных данных)
// false — только в случае критических ошибок (файл не найден, не удалось открыть и т.п.)
bool parseFile(const std::string& path, std::vector<std::shared_ptr<Curve>>& curves);