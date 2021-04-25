#include <algorithm>
#include <iostream>
#include <libgeometry/func.h>
#include <libgeometry/parsing.h>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string input, figureName;

    int figures_count;
    cout << "Enter number:" << endl;
    cin >> figures_count;
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
            parsing_circle(input, &figures[i]);
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

    float perimeter, area;
    cout << endl;
    for (int i = 0; i < figures_count; i++) {
        if (figures[i].tag == CIRCLE)
            print_circle(&figures[i], &perimeter, &area);
        if (figures[i].tag == TRIANGLE)
            print_triangle(&figures[i], &perimeter, &area);
    }
}
