#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

string word_tolower(string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

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

Figures identify(string figure) {
    string figureName;
    figure = word_tolower(figure);

    figureName = "circle";
    if (figure == figureName) return Circle;

    figureName = "triangle";
    if (figure == figureName) return Triangle;

    return Error;
}

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

string parse_name(string input)
{
    string figureName;
    if (input.substr(0, 1) == " ") {
        input.erase(0, input.find_first_not_of(" "));
    }
    if (input.substr(input.find("(") - 1, 1) == " ") {
        input = input.erase(input.find(" "), input.find("(") - input.find(" "));
    }
    figureName = input.substr(0, input.find("("));
    return figureName;
}

int main()
{
    string input, figureName;
    getline(cin, input);
    figureName = parse_name(input);

    switch (identify(figureName)) {
    case Circle:
        circle Object_circle;
        parse_circle(input, &Object_circle);
        cout << "circle" << endl;
        cout << "Point =  " << Object_circle.Point[0] << ' ' << Object_circle.Point[1] << endl;
        cout << "radius = " << Object_circle.Number << endl;
        Circle_math(Object_circle);
        break;
    case Triangle:
        triangle Object_triangle;
        parse_triangle(input, &Object_triangle);
        cout << "triangle" << endl;
        cout << "Point 1: " << Object_triangle.Point1[0] << ' ' << Object_triangle.Point1[1] << endl;
        cout << "Point 2: " << Object_triangle.Point2[0] << ' ' << Object_triangle.Point2[1] << endl;
        cout << "Point 3: " << Object_triangle.Point3[0] << ' ' << Object_triangle.Point3[1] << endl;
        cout << "Point 4: " << Object_triangle.Point4[0] << ' ' << Object_triangle.Point4[1] << endl;
        Triangle_math(Object_triangle);
        break;
    case Error:
        cout << input << endl;
        cout << '^' << endl;
        cout << "Error in name";
    }
}
