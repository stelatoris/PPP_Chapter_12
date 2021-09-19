//ppp_ch12.cpp

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
using namespace Graph_lib;

int main()
try
{    
    // Window
    Point tl{ 100, 100 };
    Simple_window win{ tl, 600, 400, "Chapter 13 Ex 1" };

    // Arc tests
    Graph_lib::Arc ar1{ Point{400,300},200,100,1,180 };
    ar1.set_color(Color::red);
    win.attach(ar1);

    win.wait_for_button();

}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}