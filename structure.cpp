#include "structure.h"
#include "gui/display.h"
#include <SDL3/SDL_scancode.h>


Structure::Structure() {

    buttons = new std::vector<Button*>;

    int size = 50;

    int distance = 10;

    int x_start = 100;
    int y_start = 170;



    int x = x_start;
    int y = y_start;


    for(int i = 1; i <= 9; i++) {


        buttons->push_back(new Button(SDL_Scancode(i+29), x, y, size, size));
        

        if (i % 3 == 0) {

            x = x_start;

            y = y + size + distance;

            continue;
        }
        
        x = x + size + distance;

    }
    
    display = new Display(100, 20, 170, 150);

    display->add_char(SDL_SCANCODE_4);
    display->add_char(SDL_SCANCODE_2);

    display->result = 42;

}


std::vector<Button*>* Structure::get_buttons() {

    return buttons;
}

Display* Structure::get_display() {

    return display;
}
