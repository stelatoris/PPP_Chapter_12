// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// Chapter 13 Exercise 5
/*
*   Define the functions from exercise 4 for a Circle and an Ellipse. Place the
*   connection points on or outside the shape but not outside the bounding
*   rectangle.
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

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
    
    // Circle
    Circle c1{ Point{100,200},50 };
    win.attach(c1);

    Point pc_center = center(c1);
    Mark m_c_center{ pc_center,'x' };
    win.attach(m_c_center);

    Point pcn = n(c1);
    Mark m_cn{ pcn,'x' };
    win.attach(m_cn);

    Point pce = e(c1);
    Mark m_ce{ pce,'x' };
    win.attach(m_ce);

    Point pcs = s(c1);
    Mark m_cs{ pcs,'x' };
    win.attach(m_cs);

    Point pcw = w(c1);
    Mark m_cw{ pcw,'x' };
    win.attach(m_cw);

    Point pcne = ne(c1);
    Mark m_cne{ pcne,'x' };
    win.attach(m_cne);

    Point pcse = se(c1);
    Mark m_cse{ pcse,'x' };
    win.attach(m_cse);

    Point pcsw = sw(c1);
    Mark m_csw{ pcsw,'x' };
    win.attach(m_csw);

    Point pcnw = nw(c1);
    Mark m_cnw{ pcnw,'x' };
    win.attach(m_cnw);

    win.wait_for_button();

    // Ellipse
    Graph_lib::Ellipse e1{ Point{300,400},200,100 };
    win.attach(e1);

    Point pe_center = center(e1);
    Mark m_e_center{ pe_center,'x' };
    win.attach(m_e_center);
    
    Point pen = n(e1);
    Mark m_en{ pen,'x' };
    win.attach(m_en);

    Point pes = s(e1);
    Mark m_es{ pes,'x' };
    win.attach(m_es);

    Point pee = e(e1);
    Mark m_ee{ pee,'x' };
    win.attach(m_ee);

    Point pew = w(e1);
    Mark m_ew{ pew,'x' };
    win.attach(m_ew);
    
    Point pene = ne(e1);
    Mark m_ene{ pene,'x' };
    win.attach(m_ene);

    Point pese = se(e1);
    Mark m_ese{ pese,'x' };
    win.attach(m_ese);

    Point pesw = sw(e1);
    Mark m_esw{ pesw,'x' };
    win.attach(m_esw);

    Point penw = nw(e1);
    Mark m_enw{ penw,'x' };
    win.attach(m_enw);

    win.wait_for_button();

    //-----------------------------------------------------------
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}