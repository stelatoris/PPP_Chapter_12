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
    : a{30}, s{20}
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
        double tip_angle = atan2(y_diff, x_diff)*180/PI;

        r_arm.x = point(1).x - cos((tip_angle+a) * (PI / 180))*s;
        r_arm.y = point(1).y - sin((tip_angle+a) * (PI / 180))*s;

        l_arm.x = point(1).x - cos((tip_angle-a) * (PI / 180)) * s;
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

//----------------------------------------------------------------------
// Exercise 4

Point n(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width()/2;
    int y = r.point(0).y;

    return Point{ x,y };
}

Point s(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height();

    return Point{ x,y };
}

Point e(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height()/2;

    return Point{ x,y };
}

Point w(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height() / 2;

    return Point{ x,y };
}

Point ne(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y;

    return Point{ x,y };
}

Point nw(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x;
    int y = r.point(0).y;

    return Point{ x,y };
}

Point se(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height();

    return Point{ x,y };
}

Point sw(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height();

    return Point{ x,y };
}

Point center(Graph_lib::Rectangle& const r)
{
    int x = r.point(0).x + r.width()/2;
    int y = r.point(0).y + r.height()/2;

    return Point{ x,y };
}





int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 1000, 600, "Chapter 13 Ex 1" };

    
    
    
    int x_size=win.x_max();
    int y_size=win.y_max();

    Lines grid_50x50;

    for(int x=50; x<x_size; x+=50)
      grid_50x50.add(Point{x,0},Point{x,y_size});

    for(int y=50; y<y_size; y+=50)
      grid_50x50.add(Point{0,y},Point{x_size,y});

    grid_50x50.set_color(Color::red);
    win.attach(grid_50x50);

      Lines grid_100x100;

    for(int x=100; x<x_size; x+=100)
      grid_100x100.add(Point{x,0},Point{x,y_size});

    for(int y=100; y<y_size; y+=100)
      grid_100x100.add(Point{0,y},Point{x_size,y});

    grid_100x100.set_color(Color::green);
    win.attach(grid_100x100);
    

    // Arc tests
    //Graph_lib::Arc ar1{ Point{400,300},200,100,1,180 };
    //ar1.set_color(Color::red);
    //win.attach(ar1);

    //win.wait_for_button();

    /*
    Graph_lib::Rounded_box rb1{ tl, 576,367,32 };
    rb1.set_color(Color::blue);

    win.attach(rb1);

    win.wait_for_button();    
    */

    //-----------------------------------------------------------
    // Ex-03
    /*
    Graph_lib::Arrow ar1{ Point{300,300}, Point{500,200} };
    ar1.set_head_angle(20);
    ar1.set_head_size(50);
    win.attach(ar1);
    win.wait_for_button();
    */

    Graph_lib::Rectangle rec1{ Point{150,100},200,100 };
    win.attach(rec1);

    Point pn = n(rec1);
    Mark mn{ pn,'x' };
    win.attach(mn);

    Point ps = s(rec1);
    Mark ms{ ps,'x' };
    win.attach(ms);

    Point pe = e(rec1);
    Mark me{ pe,'x' };
    win.attach(me);

    Point pw = w(rec1);
    Mark mw{ pw,'x' };
    win.attach(mw);

    Point pne = ne(rec1);
    Mark mne{ pne,'x' };
    win.attach(mne);

    Point pse = se(rec1);
    Mark mse{ pse,'x' };
    win.attach(mse);

    Point psw = sw(rec1);
    Mark msw{ psw,'x' };
    win.attach(msw);

    Point pnw = nw(rec1);
    Mark mnw{ pnw,'x' };
    win.attach(mnw);

    Point p_center = center(rec1);
    Mark m_center{ p_center,'x' };
    win.attach(m_center);

    win.wait_for_button();

    //-----------------------------------------------------------


}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}