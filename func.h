#pragma once
#include "parsing.h"
void Circle_math(circle Object_circle);
void Triangle_math(triangle Object_triangle);
enum Figures {
    Circle, Triangle, Error
};

struct circle
{
    float Point[2];
    float Number;
};

struct triangle
{
    float Point1[2];
    float Point2[2];
    float Point3[2];
    float Point4[2];
};
