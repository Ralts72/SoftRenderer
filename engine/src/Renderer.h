#pragma once

#include "Math.h"

class A
{};

class Bresenham : public A
{
public:
    Bresenham(const Vec2& p1, const Vec2& p2) : p1(p1), p2(p2) {

    }

private:
    Vec2 p1, p2;
};
