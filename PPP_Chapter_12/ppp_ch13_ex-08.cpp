//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

//----------------------------------------------------------------------
// Exercise 8

Regular_hexagon::Regular_hexagon(Point p, int distance)
    : c{ p }, d{ distance }
{
    add(p);
    find_points();
}

void Regular_hexagon::draw_lines() const
{
    if (color().visibility())
        for (int i = 2; i < number_of_points(); i += 1)
            fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
}

int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 9" };

    Regular_hexagon rh1{ Point {200,200},100 };
    win.attach(rh1);

    win.wait_for_button();   
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}