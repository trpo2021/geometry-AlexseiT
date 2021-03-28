#include "func.h"
#include <iostream>
#include <string>
#include <algorithm>
void Circle_math(circle Object_circle)
{
    float perimetr = 2 * 3.14 * Object_circle.Number;
    float area = 3.14 * Object_circle.Number * Object_circle.Number;

    cout << "perimetr = " << perimetr << endl;
    cout << "area = " << area << endl;
}

void Triangle_math(triangle Object_triangle)
{
    float area = 0.5 * abs((Object_triangle.Point2[0] - Object_triangle.Point1[0]) * (Object_triangle.Point3[1] - Object_triangle.Point1[1]) - (Object_triangle.Point3[0] - Object_triangle.Point1[0]) * (Object_triangle.Point2[1] - Object_triangle.Point1[1]));
    cout << "area = " << area << endl;
}
