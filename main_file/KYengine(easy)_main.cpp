//KY_Game engine example
#include <iostream>
#include "KY_Game_Tool.h"
using namespace std; 

#define END_POINT 100, 100

int main() {
    _KYbuild_ thing_tool; 

    auto text = thing_tool.Build_text("hello", 2., 1., _KYF_color_::BLUE);
    auto backgrand = thing_tool.Build_background(_KYF_QBS_());
    auto graph = thing_tool.Build_graph("Spider_ASCII_art.txt");
    var event = thing_tool.Build_event();

    var text2 = thing_tool.Build_text("very good", 25., 25.); 
    var graph2 = _KYbuild_::Build_graph("cartoon.txt"); 

    graph.set_point(0,50);
    graph.set_color(_KYF_color_::RED); 

    graph2.set_color(_KYF_color_::GREEN); 
    graph2.set_point(15, 80); 


    thing_tool.add(text); 
    thing_tool.add(text2); 
    thing_tool.add(graph); 
    thing_tool.add(graph2); 
    thing_tool.add(backgrand); 

    thing_tool.Draw_init(); 

    text2.eraser(); 
   
    while (event.get_event() != 'q') {
		std::cout << event.to_HEX() << "\n";
        if (event.get_event_memory() == 'w') {
            graph2.up();
        }
        else if (event.get_event_memory() == 's') {
            graph2.down(); 
        }
        else if (event.get_event_memory() == 'a') {
            graph2.left();
        }
        else if (event.get_event_memory() == 'd') {
            graph2.right();
        }
        else if (event.get_event_memory() == 'e') {
            graph2.up_right();
        }
    }
    KY_engine::Graph_Window MOVE;
    MOVE.gotoxy(END_POINT);


    return 0; 
}
