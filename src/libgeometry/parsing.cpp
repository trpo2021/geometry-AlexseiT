#include <algorithm>
#include <iostream>
#include <libgeometry/parsing.h>
#include <string>

std::string word_tolower(std::string word)
{
    int n = word.length();
    for (int i = 0; i < n; i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

Figures identify(std::string figure)
{
    std::string figureName;
    figure = word_tolower(figure);

    figureName = "circle";
    if (figure == figureName)
        return CIRCLE;

    figureName = "triangle";
    if (figure == figureName)
        return TRIANGLE;

    return ERROR;
}

void parsing_circle(std::string input, mass_object* circl)
{
    size_t end;
    input = input.erase(0, 6);
    if (input[0] == '(') {
        input.erase(0, 1);
        circl->obj_circle.point[0] = stod(input, &end);
        input = input.erase(0, end);
        circl->obj_circle.point[1] = stod(input, &end);
        input = input.erase(0, end + 1);
        circl->obj_circle.number = stod(input, &end);
    };
}

void parsing_triangle(std::string input, mass_object* triang)
{
    size_t end;
    input = input.erase(0, 8);
    if ((input[0] == '(') && (input[1] == '(')) {
        input = input.erase(0, 2);
        replace(input.begin(), input.end(), ',', ' ');
        triang->obj_triagle.point_1[0] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_1[1] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_2[0] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_2[1] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_3[0] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_3[1] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_4[0] = stod(input, &end);
        input.erase(0, end);
        triang->obj_triagle.point_4[1] = stod(input, &end);
        input.erase(0, end);
    }
}

std::string parsing_name(std::string* input)
{
    std::string figureName;
    if (input->substr(0, 1) == " ") {
        input->erase(0, input->find_first_not_of(" "));
    }
    if (input->substr(input->find("(") - 1, 1) == " ") {
        input->erase(input->find(" "), input->find("(") - input->find(" "));
    }
    figureName = input->substr(0, input->find("("));
    return figureName;
}
