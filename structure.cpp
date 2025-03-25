#include "structure.h"


Structure::Structure() {

    buttons = new std::vector<Button*>;

    int size = 50;

    int distance = 10;

    int x_start = 100;
    int y_start = 100;



    int x = x_start;
    int y = y_start;


    for(int i = 1; i <= 9; i++) {


        buttons->push_back(new Button(i, x, y, size, size));
        

        if (i % 3 == 0) {

            x = x_start;

            y = y + size + distance;

            continue;
        }
        
        x = x + size + distance;

    }


    // buttons->push_back(new Button(3, 100, 100, 50, 50));
    //
    // buttons->push_back(new Button(5, 160, 100, 50, 50));
}


std::vector<Button*>* Structure::get_buttons() {

    return buttons;
}
