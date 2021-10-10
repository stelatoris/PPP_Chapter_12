//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

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

Rounded_box::Rounded_box(Point p, int ww, int hh, int rr)
    : w{ ww }, h{ hh }, r{ rr }
{
    if (h <= 0 || w <= 0 || r <= 0)
        error("Bad rectangle: non-positive side/radius");
    add(p);
}

void Rounded_box::draw_lines() const
{
    if (color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x + w - r - r, point(0).y, r + r, r + r, 0, 90);       // top right rounded corner 
        fl_arc(point(0).x, point(0).y, r + r, r + r, 90, 180);       // top left rounded corner 
        fl_arc(point(0).x, point(0).y + h, r + r, r + r, 180, 270);    // bottom left rounded corner 
        fl_arc(point(0).x + w - r - r, point(0).y + h, r + r, r + r, 270, 360);  // bottom right rounded corner

        fl_line(point(0).x + r, point(0).y, point(0).x + w - r, point(0).y);               // top edge
        fl_line(point(0).x + w, point(0).y + r, point(0).x + w, point(0).y + h + r);   // right edge
        fl_line(point(0).x + r, point(0).y + h + r + r, point(0).x + w - r, point(0).y + h + r + r);   // bottom edge
        fl_line(point(0).x, point(0).y + r, point(0).x, point(0).y + h + r);               // left edge
    }
}

//----------------------------------------------------------------------
// Exercise 3

Arrow::Arrow(Point tail, Point head)
    : a{ 30 }, s{ 20 }
{
    add(tail);
    add(head);
}

void Arrow::draw_lines() const
{
    if (color().visibility()) {
        Point r_arm;    // right arm of tip
        Point l_arm;    // left arm of tip
        double x_diff = point(1).x - point(0).x;
        double y_diff = point(1).y - point(0).y;
        double tip_angle = atan2(y_diff, x_diff) * 180 / PI;

        r_arm.x = point(1).x - cos((tip_angle + a) * (PI / 180)) * s;
        r_arm.y = point(1).y - sin((tip_angle + a) * (PI / 180)) * s;

        l_arm.x = point(1).x - cos((tip_angle - a) * (PI / 180)) * s;
        l_arm.y = point(1).y - sin((tip_angle - a) * (PI / 180)) * s;

        Polygon poly;
        poly.add(Point{ point(1).x, point(1).y });
        poly.add(r_arm);
        poly.add(l_arm);
        poly.set_fill_color(Color::black);

        poly.draw_lines();  // draw arrow head
        Shape::draw_lines(); // draw arrow line
    }
}


int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 6" };

    Box box1{ Point{100,100},"Window" };
    win.attach(box1);

    win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}