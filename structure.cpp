#include "structure.h"


Structure::Structure() {

    buttons = new std::vector<Button*>;

    buttons->push_back(new Button(100, 100, 50, 50));

    buttons->push_back(new Button(160, 100, 50, 50));
}


std::vector<Button*>* Structure::get_buttons() {

    return buttons;
}
