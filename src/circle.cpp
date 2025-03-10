// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>

#define _USE_MATH_DEFINES

Circle::Circle(double r) { setRadius(std::abs(r)); }

bool Circle::setRadius(double r) {
  if (r < 0) {
    return false;
  }
  radius = r;
  ference = 2 * M_PI * r;
  area = M_PI * r * r;
  return true;
}

bool Circle::setFerence(double f) {
  if (f < 0) {
    return false;
  }
  ference = f;
  radius = f / (2 * M_PI);
  area = M_PI * radius * radius;
  return true;
}

bool Circle::setArea(double a) {
  if (a < 0) {
    return false;
  }
  area = a;
  radius = std::sqrt(a / M_PI);
  ference = 2 * M_PI * radius;
  return true;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }