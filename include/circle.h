// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
class Circle {
private:
    double radius;
    double ference;
    double area;

public:
    Circle(double r);

    bool setRadius(double r);
    bool setFerence(double f);
    bool setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
