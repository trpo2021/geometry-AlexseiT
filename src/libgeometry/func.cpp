#include <cmath>
#include <iostream>
#include <libgeometry/func.h>
#include <string>
using namespace std;

void find_circle_param(mass_object circl, float* perimeter, float* area)
{
    *perimeter = 2 * 3.14 * circl.obj_circle.number;

    *area = 3.14 * circl.obj_circle.number * circl.obj_circle.number;
}

double distance_between_points(double x1, double x2, double y1, double y2)
{
    double i = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return i;
}

void find_triangle_param(mass_object triang, float* perimeter, float* area)
{
    double x1 = triang.obj_triagle.point_1[0];
    double x2 = triang.obj_triagle.point_2[0];
    double x3 = triang.obj_triagle.point_3[0];
    double y1 = triang.obj_triagle.point_1[1];
    double y2 = triang.obj_triagle.point_2[1];
    double y3 = triang.obj_triagle.point_3[1];

    *perimeter = distance_between_points(x1, x2, y1, y2)
        + distance_between_points(x2, x3, y2, y3)
        + distance_between_points(x3, x1, y3, y1);

    *area = abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}

void print_circle(mass_object* circl, float* perimeter, float* area)
{
    cout << circl->order_number << "."

        << "circle(" << circl->obj_circle.point[0] << ' ' << circl->obj_circle.point[1] << ", "

        << circl->obj_circle.number << ")" << endl;

    find_circle_param(*circl, perimeter, area);

    cout << "Perimetr: " << *perimeter << endl;

    cout << "Area: " << *area << endl;
}

void print_triangle(mass_object* triang, float* perimeter, float* area)
{
    cout << triang->order_number << "."
        << "triangle((" << triang->obj_triagle.point_1[0] << ' '
        << triang->obj_triagle.point_1[1] << "," << triang->obj_triagle.point_2[0] << ' '
        << triang->obj_triagle.point_2[1] << "," << triang->obj_triagle.point_3[0] << ' '
        << triang->obj_triagle.point_3[1] << "," << triang->obj_triagle.point_4[0] << ' '
        << triang->obj_triagle.point_4[1] << "))" << endl;

    find_triangle_param(*triang, perimeter, area);

    cout << "Perimeter: " << *perimeter << endl;

    cout << "Area: " << *area << endl;
}
