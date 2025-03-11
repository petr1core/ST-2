// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>

#define _USE_MATH_DEFINES

Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  double absR = std::abs(r);
  radius = absR;
  ference = 2 * M_PI * absR;
  area = M_PI * absR * absR;
}

void Circle::setFerence(double f) {
  double absF = std::abs(f);
  ference = absF;
  radius = absF / (2 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
  double absA = std::abs(a);
  area = absA;
  radius = std::sqrt(absA / M_PI);
  ference = 2 * M_PI * radius;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }