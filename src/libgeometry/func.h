#pragma once

enum Figures { CIRCLE, TRIANGLE, ERROR };

struct circle {
    float point[2];
    float number;
};

struct triangle {
    float point_1[2];
    float point_2[2];
    float point_3[2];
    float point_4[2];
};

struct mass_object {
    Figures tag;
    int order_number;
    union {
        struct circle obj_circle;
        struct triangle obj_triangle;
    };
};
double circle_area(double number);

double circle_p(double number);

double
triangle_area(double x1, double x2, double x3, double y1, double y2, double y3);

double
triangle_p(double x1, double x2, double x3, double y1, double y2, double y3);

double distance_between_points(double x1, double x2, double y1, double y2);

void find_circle_param(mass_object circl, float* perimeter, float* area);

void find_triangle_param(mass_object triang, float* perimeter, float* area);

void print_circle(mass_object* circl, float* perimeter, float* area);

void print_triangle(mass_object* triang, float* perimeter, float* area);

void circle_circle(circle* cir, int countC, int count);
