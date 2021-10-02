//----------------------------------------------------------------------
// Exercise 4
/*
*   4. Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each
*   takes a Rectangle argument and returns a Point. These functions define
*   “connection points” on and in the rectangle. For example, nw(r) is the
*   northwest (top left) corner of a Rectangle called r.
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

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
    Simple_window win{ tl, 1000, 600, "Chapter 13 Ex 4" };
  
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