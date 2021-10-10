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


//----------------------------------------------------------------------
// Exercise 7

void RGB_Color_Chart(Vector_ref<Graph_lib::Rectangle>& vr, Simple_window& win)
{
    int s_w{ 20 };
    int s_h{ 20 };

    int R{ 270 };
    int G{ 0 };
    int B{ 0 };

    for (int r = 0; r < 2; ++r) {
        int row = r * 200;

        for (int b = 0; b < 5; ++b) {
            int column = b * 200;
            if (b == 4 && r == 1) B = 255;   // last set

            for (int i = 0; i < 10; ++i) {  // i is for Y axis
                if (i == 0) R = 255;

                for (int j = 0; j < 10; ++j) {  // j is for X axis

                    if (j == 9) G = 255;

                    vr.push_back(new Graph_lib::Rectangle{ Point{column + j * s_w,row + i * s_h},s_w,s_h });

                    vr[vr.size() - 1].set_fill_color(fl_rgb_color(R, G, B));

                    win.attach(vr[vr.size() - 1]);
                    G += 30;
                }
                if (i == 0) R = 270;
                R -= 30;
                G = 0;
            }
            R = 270;
            G = 0;
            B += 30;
        }
    }
    win.wait_for_button();
}

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

//----------------------------------------------------------------------
// Exercise 9
// 9. Tile a part of a window with Regular_hexagons (use at least eight hexagons).

Vector_ref<Graph_lib::Regular_hexagon> vr;

void hexagon_tiles(int distance, Simple_window& win)
{
    // First find location of first tile based on it's size and place closest to 0,0
    // Use the hexagon points of 1st tile to find offset to place next tile 

    Point first_center;    // center point for 1st hexagon
    first_center.x = distance+1;
    first_center.y= sin(60 * (PI / 180)) * distance+1;

    Regular_hexagon first_tile{ first_center ,distance };
    first_tile.set_color(Color::black);
    win.attach(first_tile);

    //offset of next tile from previous tile
    int offset_x;   
    int offset_y;

    offset_x = (first_tile.point(5).x- first_tile.point(0).x) + first_tile.get_width();
    offset_y = first_tile.point(5).y- first_tile.point(0).y;

    Point prev_center = first_center;
    Point next_center = first_center;

    bool up = true; // staggered switch/ up or down.

    int x_size = win.x_max();
    int y_size = win.y_max();
    int num_x = (x_size / (distance + (first_tile.point(5).x - first_tile.point(0).x))); //how many overlapping tiles can fit on screen in X

    for (int i = 0; i < num_x; ++i) {
        if (up == true) {   // then place below or +y in FLTK coordinates
            next_center = { prev_center.x + offset_x,prev_center.y + offset_y };
            vr.push_back(new Regular_hexagon{ next_center, distance });
            up = false;
        }
        else {              // then place above or -y in FLTK coordinates
            next_center = { prev_center.x + offset_x,prev_center.y - offset_y };
            vr.push_back(new Regular_hexagon{ next_center, distance });           
            up = true;
        }
        win.attach(vr[vr.size() - 1]);
        prev_center = next_center;
    }
}


int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 9" };

    int x_size = win.x_max();
    int y_size = win.y_max();

    Lines grid_50x50;

    for (int x = 50; x < x_size; x += 50)
        grid_50x50.add(Point{ x,0 }, Point{ x,y_size });

    for (int y = 50; y < y_size; y += 50)
        grid_50x50.add(Point{ 0,y }, Point{ x_size,y });

    grid_50x50.set_color(Color::red);
    win.attach(grid_50x50);

    Lines grid_100x100;

    for (int x = 100; x < x_size; x += 100)
        grid_100x100.add(Point{ x,0 }, Point{ x,y_size });

    for (int y = 100; y < y_size; y += 100)
        grid_100x100.add(Point{ 0,y }, Point{ x_size,y });

    grid_100x100.set_color(Color::green);
    win.attach(grid_100x100);

    /*
    // 7. Make an RGB color chart (e.g., search the web for “RGB color chart”).
    Vector_ref<Graph_lib::Rectangle>vr;

    RGB_Color_Chart(vr, win);
    //----------------------------------------------------------------------------------
    */

    hexagon_tiles(100, win);
    /*Vector_ref<Graph_lib::Regular_hexagon> vr;
    for (int i = 0; i < 600; i+=100) {         
        
        vr.push_back(new Regular_hexagon{ Point{i,200}, 100 });\
        win.attach(vr[vr.size() - 1]);
        
    }*/

    win.wait_for_button();   
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}