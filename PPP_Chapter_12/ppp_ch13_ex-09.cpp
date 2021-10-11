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

    int x_size = win.x_max();
    int y_size = win.y_max();
    int num_x = (x_size / (distance + (first_tile.point(5).x - first_tile.point(0).x))); //how many overlapping tiles can fit on screen in X

    bool up = true; // staggered switch/ up or down to tile hexagons

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

    hexagon_tiles(100, win);

    win.wait_for_button();   
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}