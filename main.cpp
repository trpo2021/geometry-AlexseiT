#include <iostream>
#include <string>
using namespace std;
const double pi = 3.141592653589793238463;
int ind(string s) {
	string s1 ;
	s1 = "circle";
	if (_stricmp(s.c_str(), s1.c_str()) == 0) return 1;
	s1 = "triangle";
	if (_stricmp(s.c_str(), s1.c_str()) == 0) return 2;
	s1 = "polygon";
	if (_stricmp(s.c_str(), s1.c_str()) == 0) return 3;
	return 0;
}
int main()
{
	string s, s1, s2, figure;
	float x, y, r;
	float P, P1;
	getline(cin, s);
	s1 = s;
	if (s1.substr(s1.find("(") - 1, 1) == " ") {
		s1 = s1.erase(s1.find(" "), s1.find("(") - s1.find(" "));
	}
	s2 = s1.substr(0, s1.find("("));
	switch (ind(s2)) {
	case (1):                                      /*Окружность*/
		figure = "circle";
		cout << s1 << endl;
		s1 = s1.erase(0, 6);
		cout << s1 << endl;
		x = stof(s1.substr(1, s1.find(" ")));
		s1 = s1.erase(0, s1.find(" "));
		y = stof(s1.substr(1, s1.find(",") - 1));
		s1 = s1.erase(0, s1.find(",") + 1);
		r = stof(s1.substr(1, s1.find(")") - 1));
		cout << "name = " << figure << endl;
		cout << "Ox = " << x << endl;
		cout << "Oy = " << y << endl;
		cout << "Radius = " << r << endl;
		P = 2 * pi * r;
		cout << "Perimetr = " << P << endl;
		P1 = pi * r * r;
		cout << "Ploshad = " << P1 << endl;
		break;
	case (2):                                     /*Треугольник*/
		cout << "triangle" << endl; 
		break;
	case (3):                                     /*Полигон*/
		cout << "polygon" << endl; 
		break;
		}
}
