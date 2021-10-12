//----------------------------------------------------------------
/*  Exercise 11
    11. Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a
    300 - pixel - long y axis through the center of the ellipse.Mark the foci.
    Mark a point on the ellipse that is not on one of the axes.Draw the two
    lines from the foci to the point.
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

double find_foci_x(Graph_lib::Ellipse& const e)
{
    //c2 = a2 - b2
    int c2 = pow(e.major(),2)- pow(e.minor(), 2);

    return sqrt(c2);
}

Point point_on_ellipse(Graph_lib::Ellipse& const e)
{
    //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    
    int x = e.center().x + ((e.major()) * cos(300 * (PI / 180)));
    int y = e.center().y + ((e.minor()) * sin(300 * (PI / 180)));
    Point p{ x,y };
    return p;
}

//----------------------------------------------------------------------

int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 11" };

    // draw ellipse
    Graph_lib::Ellipse ell1{ Point{600,400},150,100 };
    win.attach(ell1);    

    // draw both axis
    Axis xa{ Axis::x, Point{400,400},400,40,"x axis * 10" };
    win.attach(xa);
    Axis ya{ Axis::y, Point{600,550},300,30,"y axis * 10" };
    win.attach(ya);

    // find and mark foci points
    Point foci1 = { ell1.center().x + find_foci_x(ell1), ell1.center().y };
    Point foci2 = { ell1.center().x - find_foci_x(ell1), ell1.center().y };
        
    Mark f1{ foci1, 'x' };
    f1.set_color(Color::red);
    Mark f2{ foci2, 'x' };
    f2.set_color(Color::red);
    win.attach(f1);
    win.attach(f2);

    Point p1 = point_on_ellipse(ell1);
    Mark mp1{ p1,'x' };
    win.attach(mp1);

    Lines l1;
    l1.add(p1, foci1);
    l1.add(p1, foci2);
    l1.set_color(Color::red);
    win.attach(l1);

    win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
