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

Arrow::Arrow(Point tail, Point head, double angle, double head_l)
    : pp1{ tail }, pp2{ head }, a{angle}, hl{ head_l }
{
    if (a <= 0 || head_l <= 0)
        error("arrow head length/angle cannot be zero");

    if (get_length() <= 0)  // length of arrow
        error("arrow length cannot be zero");
    
    add(pp1);
    add(pp2);
}

Point Arrow::r_arm() const
{
    //double angle = get_angle() + a;
    double m = tan(a*(PI/180)); // convert angle to slope

    int x2, y2;   // coordinates of 2nd point of arrow arm

    x2 = pp2.x + ((hl+ get_angle())/ (sqrt((1 + pow(m, 2)))));  //pp2 is point on arrow head

    y2 = pp2.y + m * ((hl + get_angle())/ (sqrt((1 + pow(m, 2)))));

    return Point{ x2,y2 };
}

void Arrow::draw_lines() const
{
    
    Point r_arm = Arrow::r_arm();
    fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
    fl_line(pp2.x, pp2.y, r_arm.x, r_arm.y);
    

}

/*
// Ex 3 - Arrow

Arrow::Arrow(Point tail, Point tip)
{
    add(tail);
    add(tip);
}

void Arrow::draw_lines() const
{
    constexpr double PI = 3.14159265;

    int diff_x = point(1).x - point(0).x;
    int diff_y = point(1).y - point(0).y;
    double angle = atan2(diff_y, diff_x)*180/PI;

    double x1 = point(1).x - cos((angle-iso)*PI/180) * size;
    double y1 = point(1).y - sin((angle-iso)*PI/180) * size;

    double x2 = point(1).x - cos((angle+iso)*PI/180) * size;
    double y2 = point(1).y - sin((angle+iso)*PI/180) * size;

    Polygon head;
    head.add(point(1));
    head.add(Point{int(x1), int(y1)});
    head.add(Point{int(x2), int(y2)});
    head.set_fill_color(color());

    head.draw_lines();          // draw arrow head
    Shape::draw_lines();        // draw line
}
*/

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

    Graph_lib::Arrow ar1{ Point{300,200},Point{400,300},1.0,50.0 };
    win.attach(ar1);
    win.wait_for_button();

    double m1 = ar1.get_slope();
    double a1 = ar1.get_angle();
    double l1 = ar1.get_length();
    double x1 = ar1.get_p1().x;
    double y1 = ar1.get_p1().y;
    double x2 = ar1.get_p2().x;
    double y2 = ar1.get_p2().y;
    double slope1 = 1.0*(ar1.get_p2().y - ar1.get_p1().y) / (ar1.get_p2().x - ar1.get_p1().x);
    Point r_arm = ar1.r_arm();
    double r_arm_d = sqrt(pow((x2 - ar1.r_arm().x), 2) + pow((y2 - ar1.r_arm().y), 2));
    double y3 = 300 + (tan(45 * (PI / 180))) * (50 / (sqrt((1 + pow((tan(45 * (PI / 180))), 2)))));

    cout << "slope "<<m1 << '\n';
    cout << "angle " << a1 << '\n';
    cout << "length " << l1 << '\n';
    cout << "p1 " << ar1.get_p1().x <<','<< ar1.get_p1().y<< '\n';
    cout << "p2 " << ar1.get_p2().x << ',' << ar1.get_p2().y << '\n';
    cout << "slope of line is " << slope1<<'\n';
    cout << " angle manually " << atan(m1)<<'\n';
    cout << "p of r_arm " << ar1.r_arm().x << ',' << ar1.r_arm().y << '\n';
    cout << "r_arm length " << r_arm_d << '\n';
    cout << " tan 45 =" << tan(45*(PI / 180))<< '\n';
    cout << "tan inverse of 1 is " << atan(1) * 180 / PI << '\n';
    cout << "y3 = " << y3 << '\n';


  

}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}