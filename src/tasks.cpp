// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double rope_gap() {
  Circle earth(6378100.0); // Earth's radius in meters
  double original_c = earth.getFerence();
  Circle extended(0.0);
  extended.setFerence(original_c + 1.0);
  return extended.getRadius() - earth.getRadius();
}

double pool_cost() {
  Circle pool(3.0);
  Circle poolWithPath(4.0);
  double pathArea = poolWithPath.getArea() - pool.getArea();
  double fenceLength = poolWithPath.getFerence();
  return pathArea * 1000.0 + fenceLength * 2000.0;
}
