// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, Constructor) {
    Circle c(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
}

TEST(CircleTest, SetRadius) {
    Circle c(0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 4 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 4 * M_PI);
}

TEST(CircleTest, SetFerence) {
    Circle c(0);
    c.setFerence(2 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
}

TEST(CircleTest, SetArea) {
    Circle c(0);
    c.setArea(M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * (-5.0));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SequentialSet_Radius_Area) {
    Circle c(2.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 6 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 9 * M_PI);
    
    c.setArea(25 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 10 * M_PI);
}

TEST(CircleTest, SequentialSet_Ference_Area) {
    Circle c(0);
    c.setFerence(10 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 25 * M_PI);
    
    c.setArea(100 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 20 * M_PI);
}

TEST(CircleTest, MultipleChanges) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(10 * M_PI);
    c.setArea(36 * M_PI);
    
    EXPECT_DOUBLE_EQ(c.getRadius(), 6.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 12 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 36 * M_PI);
}

TEST(CircleTest, HugeRadius) {
    Circle c(1e9);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e9);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e18);
}

TEST(CircleTest, TinyRadius) {
    Circle c(1e-10);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e-10);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e-20);
}

TEST(CircleTest, NegativeArea) {
    Circle c(0);
    c.setArea(-25 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0); // Радиус всегда положителен
    EXPECT_DOUBLE_EQ(c.getFerence(), 10 * M_PI);
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c(0);
    c.setFerence(-6 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), -3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 9 * M_PI);
}

TEST(CircleTest, SetZeroArea) {
    Circle c(0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, GettersAfterSetRadius) {
    Circle c(0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 14 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 49 * M_PI);
}

TEST(CircleTest, GettersAfterSetFerence) {
    Circle c(0);
    c.setFerence(18 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 9.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 18 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 81 * M_PI);
}

TEST(CircleTest, GettersAfterSetArea) {
    Circle c(0);
    c.setArea(121 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 11.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 22 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 121 * M_PI);
}

TEST(CircleTest, PrecisionAfterSetArea) {
    Circle c(0);
    double expectedRadius = std::sqrt(2.0 / M_PI);
    c.setArea(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), expectedRadius);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * expectedRadius);
}

TEST(TaskTest, RopeGap) {
    double expected = 1.0 / (2 * M_PI);
    EXPECT_DOUBLE_EQ(rope_gap(), expected);
}

TEST(TaskTest, PoolCost) {
    double expected = 23000 * M_PI;
    EXPECT_DOUBLE_EQ(pool_cost(), expected);
}