#include <iostream>
#include <string>
using namespace std;
const double pi = 3.141592653589793238463;
enum Figures {
	Circle, Trinagle, Polygon, Error
};

struct circle {
	float Point;
	float Point1;
	float Number;
};

string word_tolower(string word)
{
	int n = word.length();
	for (int i = 0; i < n; i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}

void Сircle_func(float Number) {
	float perimetr = 2 * pi * Number;
	float area = pi * Number * Number;
	cout << "Perimetr: " << perimetr << endl;
	cout << "area: " << area << endl;
}

Figures identify(string figure) {
	string figureName;
	figure = word_tolower(figure);

	figureName = "circle";
	if (figure == figureName) return Circle;

	figureName = "triangle";
	if (figure == figureName) return Trinagle;

	figureName = "polygon";
	if (figure == figureName) return Polygon;

	return Error;
}

int main() {
	string ObjectName;
	string ObjectString;
	circle Object;

	getline(cin, ObjectString);

	if (ObjectString.substr(0, 1) == " ") {
		ObjectString.erase(0, ObjectString.find_first_not_of(" "));
	}
	if (ObjectString.substr(ObjectString.find("(") - 1, 1) == " ") {
		ObjectString = ObjectString.erase(ObjectString.find(" "), ObjectString.find("(") - ObjectString.find(" "));
	}
	ObjectName = ObjectString.substr(0, ObjectString.find("("));


	switch (identify(ObjectName)) {
			case Circle:
			ObjectString = ObjectString.erase(0, 6);
			Object.Point = stof(ObjectString.substr(1, ObjectString.find(" ")));
			ObjectString = ObjectString.erase(0, ObjectString.find(" "));
			Object.Point1 = stof(ObjectString.substr(1, ObjectString.find(",") - 1));
			ObjectString = ObjectString.erase(0, ObjectString.find(",") + 1);
			Object.Number = stof(ObjectString.substr(1, ObjectString.find(")") - 1));
			cout << "Point = " << Object.Point << endl;
			cout << "Point1 = " << Object.Point1 << endl;
			cout << "Number = " << Object.Number << endl;
			Сircle_func(Object.Number);
			break;
		case Trinagle:
			cout << "triangle" << endl;
			break;
		case Polygon:
			cout << "polygon" << endl;
			break;
		case Error:
			cout << "Error: the figure was not found";
	}
}
