# cadex-curves-cpp-test
# CAD Exchanger probation C++ test: 3D curves hierarchy (circles, ellipses, helix)

Реализация тестового задания на позицию C++ разработчика в CAD Exchanger.

## Задание
Поддержка иерархии 3D-кривых: круги, эллипсы, 3D-спирали (helix).  
Чтение из файла, вывод точек и производных при t = π/4, фильтрация и сортировка кругов, сумма радиусов.

## Технологии
- C++11
- STL (vector, shared_ptr, algorithm, fstream и др.)
- CMake для сборки

## Структура проекта
```
├── CMakeLists.txt
├── README.md
├── main.cpp
│
├── curves/
│   ├── Curve.h                 # struct Point, using Vector = Point, class Curve (абстрактный)
│   ├── Circle.h                # class Circle : public Curve
│   ├── Circle.cpp
│   ├── Ellipse.h
│   ├── Ellipse.cpp
│   ├── Helix.h
│   └── Helix.cpp
│
└── utils/
    ├── Parser.h                # объявления parseFile(...)
    ├── Parser.cpp              # чтение файла, парсинг строк, создание объектов
    ├── Printer.h               # объявления printAllCurvesInfo(...), printCirclesAndSum(...)
    └── Printer.cpp             # реализация вывода в консоль
```
## Как собрать и запустить

## Результаты
