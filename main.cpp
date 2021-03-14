#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum Figures {
	Circle, Trinagle, Error
};

struct circle
{
	float point[2];
	float Number;
};

struct triangle
{
	float point1[2];
	float point2[2];
	float point3[2];
	float point4[2];
};


string word_tolower(string word)
{
	int n = word.length();
	for (int i = 0; i < n; i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}

void Circle_param(circle Object_circle)
{
	float perimetr = 2 * 3.14 * Object_circle.Number;
	float area = 3.14 * Object_circle.Number * Object_circle.Number;

	cout << " perimetr = " << perimetr << endl;
	cout << " area = " << area << endl;
}

void Triangle_param(triangle Object_triangle)
{
	float area = 0.5 * abs((Object_triangle.point2[0] - Object_triangle.point1[0]) * (Object_triangle.point3[1] - Object_triangle.point1[1]) - (Object_triangle.point3[0] - Object_triangle.point1[0]) * (Object_triangle.point2[1] - Object_triangle.point1[1]));
	cout << "area = " << area << endl;
}

Figures identify(string figure) {
	string figureName;
	figure = word_tolower(figure);

	figureName = "circle";
	if (figure == figureName) return Circle;

	figureName = "triangle";
	if (figure == figureName) return Trinagle;

	return Error;
}

void parse_circle()
{

}

int main()
{
	string input, figureName;
	size_t end;

	getline(cin, input);

	if (input.substr(0, 1) == " ") {
		input.erase(0, input.find_first_not_of(" "));
	}
	if (input.substr(input.find("(") - 1, 1) == " ") {
		input = input.erase(input.find(" "), input.find("(") - input.find(" "));
	}
	figureName = input.substr(0, input.find("("));


	switch (identify(figureName)) {
	case Circle:
		circle Object_circle;
		input = input.erase(0, 6);
		cout << input << endl;
		if (input[0] == '(') {
			input.erase(0, 1);
			Object_circle.point[0] = stod(input, &end);
			input = input.erase(0, end);
			Object_circle.point[1] = stod(input, &end);
			input = input.erase(0, end + 1);
			Object_circle.Number = stod(input, &end);
			cout << "Figure: circle" << endl;
			cout << "Point =  " << Object_circle.point[0] << ' ' << Object_circle.point[1] << endl;
			cout << "Number = " << Object_circle.Number << endl;
			Circle_param(Object_circle);
		}
		break;
	case Trinagle:
		triangle Object_triangle;
		float points[8];
		input = input.erase(0, 8);
		if ((input[0] == '(') && (input[1] == '(')) {
			input = input.erase(0, 2);
			replace(input.begin(), input.end(), ',', ' ');

			Object_triangle.point1[0] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point1[1] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point2[0] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point2[1] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point3[0] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point3[1] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point4[0] = stod(input, &end);
			input.erase(0, end);
			Object_triangle.point4[1] = stod(input, &end);
			input.erase(0, end);

		}
		cout << "Figure: triangle" << endl;
		cout << "Point 1:" << Object_triangle.point1[0] << ' ' << Object_triangle.point1[1] << endl;
		cout << "Point 2:" << Object_triangle.point2[0] << ' ' << Object_triangle.point2[1] << endl;
		cout << "Point 3:" << Object_triangle.point3[0] << ' ' << Object_triangle.point3[1] << endl;
		cout << "Point 4:" << Object_triangle.point4[0] << ' ' << Object_triangle.point4[1] << endl;
		Triangle_param(Object_triangle);
		break;

	case Error:
		cout << "Error: figure not found";
	}
}

