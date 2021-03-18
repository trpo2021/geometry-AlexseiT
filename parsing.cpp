#include "parsing.h"
#include <iostream>
#include <string>
#include <algorithm>
void parse_circle(string input, circle* Object_circle)
{
    size_t end;
    input = input.erase(0, 6);
    if (input[0] == '(') {
        input.erase(0, 1);
        Object_circle->Point[0] = stod(input, &end);
        input = input.erase(0, end);
        Object_circle->Point[1] = stod(input, &end);
        input = input.erase(0, end + 1);
        Object_circle->Number = stod(input, &end);
    };
}

void parse_triangle(string input, triangle* Object_triangle)
{
    size_t end;
    input = input.erase(0, 8);
    if ((input[0] == '(') && (input[1] == '(')) {
        input = input.erase(0, 2);
        replace(input.begin(), input.end(), ',', ' ');
        Object_triangle->Point1[0] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point1[1] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point2[0] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point2[1] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point3[0] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point3[1] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point4[0] = stod(input, &end);
        input.erase(0, end);
        Object_triangle->Point4[1] = stod(input, &end);
        input.erase(0, end);
    }
}
