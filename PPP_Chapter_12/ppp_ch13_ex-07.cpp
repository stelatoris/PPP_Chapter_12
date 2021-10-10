//ppp_ch13.cpp

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
    Simple_window win{ tl, 2000, 1200, "Chapter 13 Ex 7" };
    
    // 7. Make an RGB color chart (e.g., search the web for “RGB color chart”).
    Vector_ref<Graph_lib::Rectangle>vr;
        
    int s_w{ 20 };
    int s_h{ 20 };

    int R{ 270 };
    int G{ 0 };
    int B{ 0 };
    
    for (int r = 0; r < 2; ++r) {
        int row = r * 200;        

        for (int b = 0; b < 5; ++b) {
            int column = b * 200;
            if (b == 4 && r==1 ) B = 255;   // last set

            for (int i = 0; i < 10; ++i) {  // i is for Y axis
                if (i == 0) R = 255;

                for (int j = 0; j < 10; ++j) {  // j is for X axis
                    
                    if (j == 9) G = 255;             

                    vr.push_back(new Graph_lib::Rectangle{ Point{column + j * s_w,row+i * s_h},s_w,s_h });

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

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}