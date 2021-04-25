#include <libgeometry/parsing.h>
#include <libgeometry/func.h>
#include <stdlib.h>
#include <ctest.h>
CTEST(Perim_Area_Circle, Perim)
{
    double number = 2;

    double real_number = circle_p(number);

    double perim_c = 12.56;

    ASSERT_DBL_NEAR(perim_c, real_number);
}

CTEST(Perim_Area_Circle, Area)
{
    double area = 1;

    double real_area = circle_area(area);

    double area_c = 3.14;

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
