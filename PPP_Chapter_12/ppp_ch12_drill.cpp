//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
using namespace Graph_lib;

template<class T>class Vector_ref {
public:
    void push_back(T&);
    void push_back(T*);

    T& operator[](int i);
    const T& operator[](int i) const;

    int size() const;
};

int main()
try
{    
    Point x{ 100,100 };
    Simple_window win1{ x,800,1000,"Drill" };

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid1;
    for (int x = x_grid; x < x_size; x += x_grid) {
        grid1.add(Point{ x,0 }, Point{ x,y_size });     // verticle line
    }
    for (int y = y_grid; y < y_size+1; y += y_grid) {
        grid1.add(Point{ 0,y }, Point{ x_size,y });
    }

    win1.attach(grid1);

    win1.wait_for_button();

    Graph_lib::Vector_ref<Graph_lib::Rectangle>vr;

    for (int x = 0; x < 800; x += 100) {
        for (int y = 0; y < 800; y += 100) {
            if (x == y) {
                vr.push_back(new Graph_lib::Rectangle{ Point{x,y},100,100 });
                vr[vr.size() - 1].set_fill_color(Color{ Color::red });
                vr[vr.size() - 1].set_color(Color::invisible);
                
                win1.attach(vr[vr.size() - 1]);
            }
        }
    }

    win1.put_on_top(grid1);
    win1.wait_for_button();

    Image dot1{ Point{500,0},"dot.jpg" };
    Image dot2{ Point{0,200},"dot.jpg" };
    Image dot3{ Point{200,600},"dot.jpg" };
    win1.attach(dot1);
    win1.attach(dot2);
    win1.attach(dot3);
    win1.wait_for_button();

    for (int y = 0; y < 800; y += 100) {
        for (int x = 0; x < 800; x += 100) {
            Image pac{ Point{x,y},"pac.jpg" };
            win1.attach(pac);
            win1.wait_for_button();
        }
    }
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}