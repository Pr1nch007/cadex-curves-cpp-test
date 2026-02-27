# cadex-curves-cpp-test
# CAD Exchanger probation C++ test: 3D curves hierarchy (circles, ellipses, helix)

Реализация тестового задания на позицию C++ разработчика в CAD Exchanger.

## Поддерживаемые версии задания
- **v4** : генерация кривых в случайном порядке (без аргументов)
- **v5** : чтение кривых из файла (аргумент командной строки)

Программа **универсальная** — поддерживает оба режима в одном бинарнике.

## Задание
Поддержка иерархии 3D-кривых: круги, эллипсы, 3D-спирали (helix).  
Генерация/чтение из файла, вывод точек и производных при `t = π/4`, фильтрация и сортировка кругов, сумма радиусов.

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
    ├── Printer.cpp             # реализация вывода в консоль
    ├── RandomGenerator.h       # объявление generateRandomCurves(...)
    └── RandomGenerator.cpp     # реализация генерации кривых
```
## Как собрать и запустить
### Сборка
```bash
mkdir -p build && cd build
cmake ..
make -j
```

## Запуск

### Режим v4 (random — по умолчанию)
`./curves_app`

### Режим v5 (чтение файла)
`./curves_app ../../curves_to_check.txt`

## Результаты
### Режим v4 — генерация случайных кривых
```
No input file provided. Generating random curves...
All curves at t = π/4:
ID: 1  Name: "Random Circle #1"
  Point:     (4.379100, 13.270385, 5.620143)
  Derivative: (-4.723321, 4.723321, 0.000000)

ID: 2  Name: "Random Ellipse #1"
  Point:     (-5.009890, 11.398504, -7.768211)
  Derivative: (-4.637445, 1.423151, 0.000000)

ID: 3  Name: "Random Helix #1"
  Point:     (13.894762, 0.800720, -8.123317)
  Derivative: (-5.553837, 5.553837, 1.223986)

ID: 4  Name: "Random Helix #2"
  Point:     (11.272228, -3.921772, -8.336141)
  Derivative: (-3.629002, 3.629002, -0.731470)

ID: 5  Name: "Random Ellipse #3"
  Point:     (10.700944, 4.985427, -2.488604)
  Derivative: (-6.839307, 0.330751, 0.000000)

ID: 6  Name: "Random Ellipse #4"
  Point:     (5.148906, -3.535031, 1.340064)
  Derivative: (-1.844010, 2.865162, 0.000000)

ID: 7  Name: "Random Helix #5"
  Point:     (13.652035, -2.174777, -8.393664)
  Derivative: (-5.015898, 5.015898, 0.456891)

ID: 8  Name: "Random Ellipse #6"
  Point:     (7.993653, -2.721898, 2.356963)
  Derivative: (-3.681594, 2.226459, 0.000000)

ID: 9  Name: "Random Ellipse #7"
  Point:     (-8.739208, 14.306845, -4.182673)
  Derivative: (-0.151063, 6.147795, 0.000000)

ID: 10  Name: "Random Helix #8"
  Point:     (4.064835, -6.247136, -8.651484)
  Derivative: (-2.957720, 2.957720, 0.697524)

ID: 11  Name: "Random Ellipse #9"
  Point:     (-1.483970, -1.914205, 5.389237)
  Derivative: (-2.783239, 5.421152, 0.000000)

ID: 12  Name: "Random Circle #10"
  Point:     (-0.105257, 14.353696, 1.670877)
  Derivative: (-5.641322, 5.641322, 0.000000)
ID: 13  Name: "Random Helix #11"
  Point:     (-2.669808, -6.200668, -2.966947)
  Derivative: (-1.605108, 1.605108, -0.104265)


=== Circles (sorted by radius) ===
ID: 1  Name: "Random Circle #1"  Radius: 6.679784
ID: 12  Name: "Random Circle #10"  Radius: 7.978034

Total sum of radii: 14.657819
```
### Режим v5 — проверка на `curves_to_check.txt`
```
Warning: Invalid Circle (radius <= 0): C 777000111 "centering_boss" 3.000000 4.000000 -2.000000 -2.000000
Warning: Invalid Ellipse (rx/ry <= 0): E 888000111 "cam_profile" 1.000000 -2.500000 5.000000 -10.000000 2.350000
Warning: Invalid Helix (radius <= 0): H 999000111 "bolt_thread" 1.200000 5.600000 -7.000000 -4.550000 2.200000
All curves at t = π/4:
ID: 111000111  Name: "wheel_flange"
  Point:     (0.707107, 0.707107, 0.000000)
  Derivative: (-0.707107, 0.707107, 0.000000)

ID: 222000111  Name: "access_hatch"
  Point:     (1.414214, 2.121320, 0.000000)
  Derivative: (-1.414214, 2.121320, 0.000000)

ID: 333000111  Name: "screw_thread"
  Point:     (1.414214, 1.414214, 0.785398)
  Derivative: (-1.414214, 1.414214, 1.000000)

ID: 444000111  Name: "pitch_sign"
  Point:     (-6.464466, -16.464466, 30.128000)
  Derivative: (-3.535534, 3.535534, 0.000000)

ID: 555000111  Name: "cover_plate"
  Point:     (-1.292893, 7.828427, -10.896000)
  Derivative: (-0.707107, 2.828427, 0.000000)

ID: 666000111  Name: "nut_thread"
  Point:     (6.621320, -0.678680, 10.500000)
  Derivative: (-2.121320, 2.121320, 0.636620)


=== Circles (sorted by radius) ===
ID: 111000111  Name: "wheel_flange"  Radius: 1.000000
ID: 444000111  Name: "pitch_sign"  Radius: 5.000000

Total sum of radii: 6.000000
```