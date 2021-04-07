#pragma once

#include <libgeometry/func.h>
#include <string>

std::string word_tolower(std::string word);

Figures identify(std::string figure);

void parsing_circle(std::string input, mass_object* circl);

void parsing_triangle(std::string input, mass_object* triang);

std::string parsing_name(std::string* input);
