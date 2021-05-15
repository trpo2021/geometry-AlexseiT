#include <ctest.h>
#include <libgeometry/func.h>
#include <libgeometry/parsing.h>
#include <stdlib.h>
CTEST(Perim_Area_Circle, Perim)
{
    double number = 2;

    double real_number = circle_p(number);

    double perim_c = 12.5664;

    ASSERT_DBL_NEAR(perim_c, real_number);
}

CTEST(Perim_Area_Circle, Area)
{
    double number = 1;

    double real_area = circle_area(number);

    double area_c = 3.14159;

    ASSERT_DBL_NEAR(area_c, real_area);
}

CTEST(Perim_Area_Triangle, Area)
{
    double x1 = 0;
    double x2 = 1;
    double x3 = 2;
    double y1 = 0;
    double y2 = 2;
    double y3 = 1;

    double real_area = triangle_area(x1, x2, x3, y1, y2, y3);

    double area_c = 1.5;

    ASSERT_DBL_NEAR(area_c, real_area);
}

CTEST(Perim_Area_Triangle, Perim)
{
    double x1 = 0;
    double x2 = 1;
    double x3 = 2;
    double y1 = 0;
    double y2 = 2;
    double y3 = 1;

    double real_perim = triangle_p(x1, x2, x3, y1, y2, y3);

    double perim_c = 5.88635;

    ASSERT_DBL_NEAR(perim_c, real_perim);
}

CTEST(Parsing, Identify_Circle)
{
    Figures real_ind = identify("circle");

    Figures rez_circ = CIRCLE;

    ASSERT_EQUAL(rez_circ, real_ind);
}

CTEST(Parsing, Identify_Triangle)
{
    Figures real_ind = identify("triangle");

    Figures rez_triang = TRIANGLE;

    ASSERT_EQUAL(rez_triang, real_ind);
}

CTEST(Parsing, Parse_space_before_circle)
{
    std::string test = " circle(0 0, 1.5)";

    std::string real = parsing_name(&test);

    std::string rez = "circle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, Parse_space_before_triangle)
{
    std::string test = " triangle((3 -2.0, 3.0 2, 1.0 0, 3.0 -2))";

    std::string real = parsing_name(&test);

    std::string rez = "triangle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, Parse_space_after_circle)
{
    std::string test = "circle (0 0, 1.5)";

    std::string real = parsing_name(&test);

    std::string rez = "circle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, Parse_space_after_triangle)
{
    std::string test = "triangle ((3 -2.0, 3.0 2, 1.0 0, 3.0 -2))";

    std::string real = parsing_name(&test);

    std::string rez = "triangle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, Parse_double_space_circle)
{
    std::string test = " circle (0 0, 1.5)";

    std::string real = parsing_name(&test);

    std::string rez = "circle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, Parse_double_space_triangle)
{
    std::string test = " triangle ((3 -2.0, 3.0 2, 1.0 0, 3.0 -2))";

    std::string real = parsing_name(&test);

    std::string rez = "triangle";

    const char* exp_str = rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}
