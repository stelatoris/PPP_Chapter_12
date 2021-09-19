//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
using namespace Graph_lib;

//----------------------------------------------------------------------
// Exercise 1
Arc::Arc(Point p, int w, int h, int b, int e)
    : width{ w }, height{ h }, begin{ b }, end{ e }
{
    add(Point{ p.x - width,p.y - height });
}

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, width, height, begin, end);
}

//----------------------------------------------------------------------
// Exercise 2
/*
void Rounded_box::draw_lines() const
{
    Arc ptl{ Point{0,0},r,r,271,360 };    //top left corner
    Arc ptr{ Point{w,0},r,r,1,90 };    //top right corner
    Arc pbl{ Point{0,h},r,r,181,270 };    //bottom left corner
    Arc pbr{ Point{w,h},r,r,91,180 };    //bottom left corner


    if (color().visibility()) {

    }
}
*/

int main()
try
{    
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 600, 400, "Chapter 13 Ex 1" };

    // Arc tests
    //Graph_lib::Arc ar1{ Point{400,300},200,100,1,180 };
    //ar1.set_color(Color::red);
    //win.attach(ar1);

    //win.wait_for_button();

    int w{ 200 };
    int h{ 100 };
    int r{ 50 };
    Point p1{ 100,100 };

    Graph_lib::Arc ptl{ Point{p1.x,p1.y},r,r,0,45 };    //top left corner
    //Graph_lib::Arc ptr{ Point{p1.x,p1.y},r,r,1,90 };    //top right corner
    //Graph_lib::Arc pbl{ Point{p1.x,p1.y+h},r,r,181,270 };    //bottom left corner
    //Graph_lib::Arc pbr{ Point{p1.x + w,p1.y + h},r,r,91,180 };    //bottom left corner
    win.attach(ptl);
    //win.attach(ptr);
    //win.attach(pbl);
    //win.attach(pbr);

    win.wait_for_button();

}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}