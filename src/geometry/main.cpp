#include <algorithm>
#include <iostream>
#include <libgeometry/func.h>
#include <libgeometry/parsing.h>
#include <limits>
#include <string>

using namespace std;

int main()
{
    string input, figureName;

    int figures_count, countC = 0;
    float perimeter, area;
    cout << "Enter number:" << endl;
    cin >> figures_count;

    circle* cir = new circle[figures_count];
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    mass_object figures[figures_count];

    for (int i = 0; i < figures_count; i++) {
        getline(cin, input);
        figureName = parsing_name(&input);

        switch (identify(figureName)) {
        case CIRCLE:
            figures[i].tag = CIRCLE;
            figures[i].order_number = i + 1;
            parsing_circle(input, &figures[i], &cir[countC]);
            countC++;
            break;
        case TRIANGLE:
            figures[i].tag = TRIANGLE;
            figures[i].order_number = i + 1;
            parsing_triangle(input, &figures[i]);
            break;
        case ERROR:
            cout << input << endl;
            cout << '^' << endl;
            cout << "Error: figure not found";
        }
    }

    cout << endl;
    for (int i = 0; i < figures_count; i++) {
        if (figures[i].tag == CIRCLE) {
            print_circle(&figures[i], &perimeter, &area);
            cout << "interesection: " << endl;
            circle_circle(cir, countC, i);
            cout << endl;
        }
        if (figures[i].tag == TRIANGLE) {
            print_triangle(&figures[i], &perimeter, &area);
            cout << endl;
        }
    }
}
