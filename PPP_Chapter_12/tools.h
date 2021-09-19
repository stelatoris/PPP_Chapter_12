// tools.h

#include "Graph.h"
#include "std_lib_facilities.h"

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
        void draw_lines() const;

        //void draw_lines() const;

        int width() const { return w; }
        int height() const { return h; }
        int radius() const { return r; }
        

    private:
        int w;  // width
        int h;  // height
        int r;  // radius of conrner
    };
}

