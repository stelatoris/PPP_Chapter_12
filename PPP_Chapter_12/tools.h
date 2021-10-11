// tools.h

#include "Graph.h"
#include "std_lib_facilities.h"
#define PI 3.14159265

using namespace Graph_lib;

namespace Graph_lib {

    /*
     * Exercise 1
     * 1. Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
    */
    struct Arc :Shape {
        Arc(Point p, int w, int h, int b, int e);

        void draw_lines() const;

    private:
        int width;
        int height;
        int begin;  // beginning of angle to be drawn
        int end;    // end of angle to be drawn
    };

    /* ----------------------------------------------------------------------------
     * 2. Draw a box with rounded corners. Define a class Box, consisting of four
     * lines and four arcs.
    */

    struct Rounded_box :Shape {
        Rounded_box(Point p, int ww, int hh, int rr);
        Rounded_box() : w{ 50 }, h{ 50 }, r{ 5 } {}
        void draw_lines() const;

        //void draw_lines() const;

        int width() const { return w; }
        int height() const { return h; }
        int radius() const { return r; }

        void set_width(int ww) { w = ww; }
        void set_height(int hh) { h = hh; }
        void set_radius(int rr) { r = rr; }


    private:
        int w;  // width
        int h;  // height
        int r;  // radius of conrner
    };

    /* ----------------------------------------------------------------------------
     * 3. Define a class Arrow, which draws a line with an arrowhead.
    */

    struct Arrow :Shape {

        Arrow(Point tail, Point head);
        void draw_lines() const;
        void set_head_size(int head_size) { s = head_size; }
        void set_head_angle(int angle) { a = angle; }

    private:
        int a;  // angle of arrow head
        int s;  // arrow point size 
    };

    //----------------------------------------------------------------------
// Exercise 4

    Point n(Graph_lib::Rectangle& const r)
    {
        int x = r.point(0).x + r.width() / 2;
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
        int y = r.point(0).y + r.height() / 2;

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
        int x = r.point(0).x + r.width() / 2;
        int y = r.point(0).y + r.height() / 2;

        return Point{ x,y };
    }

    //----------------------------------------------------------------------
    // Exercise 5
    /*
    *   Define the functions from exercise 4 for a Circle and an Ellipse. Place the
    *   connection points on or outside the shape but not outside the bounding
    *   rectangle.
    */

    Point n(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(0 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(0 * (PI / 180)));

        return Point{ x,y };
    }

    Point e(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(90 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(90 * (PI / 180)));

        return Point{ x,y };
    }

    Point s(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(180 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(180 * (PI / 180)));

        return Point{ x,y };
    }



    Point w(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(270 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(270 * (PI / 180)));

        return Point{ x,y };
    }

    Point center(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x;
        int y = c.center().y;

        return Point{ x,y };
    }

    Point ne(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(45 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(45 * (PI / 180)));

        return Point{ x,y };
    }

    Point se(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(135 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(135 * (PI / 180)));

        return Point{ x,y };
    }

    Point sw(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(225 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(225 * (PI / 180)));

        return Point{ x,y };
    }

    Point nw(Graph_lib::Circle& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.radius() * sin(315 * (PI / 180)));
        int y = c.center().y - (c.radius() * cos(315 * (PI / 180)));

        return Point{ x,y };
    }

    // An ellipse can be defined as the locus of all points that satisfy the equations:
    // x = a cos t
    // y = b sin t

    Point center(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x;
        int y = c.center().y;

        return Point{ x,y };
    }

    Point n(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + ((c.major()) * cos(270 * (PI / 180)));
        int y = c.center().y + ((c.minor()) * sin(270 * (PI / 180)));        

        return Point{ x,y };
    }

    Point ne(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.major() * cos(315 * (PI / 180)));
        int y = c.center().y + (c.minor() * sin(315 * (PI / 180)));

        return Point{ x,y };
    }

    Point e(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.major() * cos(0 * (PI / 180)));
        int y = c.center().y + (c.minor() * sin(0 * (PI / 180)));

        return Point{ x,y };
    }

    Point s(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + ((c.major()) * cos(90 * (PI / 180)));
        int y = c.center().y + ((c.minor()) * sin(90 * (PI / 180)));

        return Point{ x,y };
    }

    Point se(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.major() * cos(45 * (PI / 180)));
        int y = c.center().y + (c.minor() * sin(45 * (PI / 180)));

        return Point{ x,y };
    }

    Point w(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + ((c.major()) * cos(180 * (PI / 180)));
        int y = c.center().y + ((c.minor()) * sin(180 * (PI / 180)));

        return Point{ x,y };
    }

    Point sw(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + (c.major() * cos(135 * (PI / 180)));
        int y = c.center().y + (c.minor() * sin(135 * (PI / 180)));

        return Point{ x,y };
    }

    Point nw(Graph_lib::Ellipse& const c)
        //Any point (x,y) on the path of the circle is x = rsin(rad), y = rcos(rad).
    {
        int x = c.center().x + ((c.major()) * cos(225 * (PI / 180)));
        int y = c.center().y + ((c.minor()) * sin(225 * (PI / 180)));

        return Point{ x,y };
    }


    //----------------------------------------------------------------------
    // Exercise 6
    /*
    *   Write a program that draws a class diagram like the one in §12.6. It will
    *   simplify matters if you start by defining a Box class that is a rectangle with
    *   a text label.
    */

    struct Box :Rounded_box {
        Box(Point pp, const string& label);

        void draw_lines() const;

        void set_font_size(int s);

    private:
        Text t;     // Text label with font and size
        string l;
    };

    Box::Box(Point p, const string& label)
        : t{ Point{p.x, p.y}, label }, Rounded_box(p, 100, 50, 5), l{label}
    {
        add(p);
        t.set_font_size(20);        
    }

    void Box::draw_lines() const
    {
        Rounded_box::draw_lines();
        t.draw_lines();      
    }

    void Box::set_font_size(int s) 
    {
        t.set_font_size(s);
        //Box::t.point(0) = Point{ 200, 200 };
        int w=int(s * l.size()*0.75 );
        int h=int( s * l.size()*0.2 );
        Box::set_width(w);
        Box::set_height(h);
    }

    //----------------------------------------------------------------------
    // Exercise 7 uses a function in main cpp 
    // 
    //----------------------------------------------------------------------
    // Exercise 8

    /*
        8. Define a class Regular_hexagon (a regular hexagon is a six-sided polygon
        with all sides of equal length). Use the center and the distance from the
        center to a corner point as constructor arguments.
    */

    struct Regular_hexagon :Shape {

        Regular_hexagon(Point p, int distance);
        void draw_lines() const;
        int get_width() const { return d; }
        int get_height() const { return point(0).y - point(2).y; }  // get top left point y distance


    private:
        int d;      // distance from center
        Point c;    // center point
        void find_points();
    };  
  

    void Regular_hexagon::find_points()
    {
        for (int x = 0; x <= 360; x += 60) {
            int p_x{ 0 };
            int p_y{ 0 };

            p_x = point(0).x - cos(x * (PI / 180)) * d;
            p_y = point(0).y - sin(x * (PI / 180)) * d;

            add(Point{ p_x ,p_y });
        }
    }
 

    //----------------------------------------------------------------------
    // Exercise 10

    /*
        10. Define a class Regular_polygon. Use the center, the number of sides (>2),
        and the distance from the center to a corner as constructor arguments.
    */

    struct Regular_polygon :Shape {

        Regular_polygon(Point p, int n_sides, int distance);
        void draw_lines() const;
        int get_width() const { return d; }
        int get_height() const { return point(0).y - point(2).y; }  // get top left point y distance


    private:
        int d;      // distance from center
        int n;      // number of sides
        Point c;    // center point
        void find_points();
    };


    void Regular_polygon::find_points()
    {
        for (int x = 0; x <= 360; x += (360/n)) {
            int p_x{ 0 };
            int p_y{ 0 };

            p_x = point(0).x - cos(x * (PI / 180)) * d;
            p_y = point(0).y - sin(x * (PI / 180)) * d;

            add(Point{ p_x ,p_y });
        }
    }


    //----------------------------------------------------------------------

}

