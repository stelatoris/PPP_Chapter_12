//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

//----------------------------------------------------------------------
// Exercise 10
/*
    10. Define a class Regular_polygon. Use the center, the number of sides (>2),
    and the distance from the center to a corner as constructor arguments.
*/

Regular_polygon::Regular_polygon(Point p, int n_sides, int distance)
    : c{ p }, n{ n_sides }, d{ distance }
{
    if (n < 3) error("Regular_polygon needs more than 2 sides");
    add(p);
    find_points();
}

void Regular_polygon::draw_lines() const
{
    if (color().visibility())
        for (int i = 2; i < number_of_points(); i += 1)
            fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
}

//----------------------------------------------------------------------

int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 10" };

    Regular_polygon rp1{ Point{200,200},5,100 };
    win.attach(rp1);
    win.wait_for_button();   
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}