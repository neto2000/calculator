#include "button.h"


bool Button::is_on_button(int mx, int my) {
    
    if (mx >= x && my >= y) {

        if (mx <= x + width && my <= y + height) {

            return true;
        }
    }


    return false;
}

void Button::execute_button() {

    std::cout << "Button clicked!\n";
}


