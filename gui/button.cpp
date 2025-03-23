#include "button.h"

Button::Button(int cvalue, int cx, int cy, int cwidth, int cheight) : GuiComponent("../textures/normal_button.png", cx, cy, cwidth, cheight) {

    value = cvalue;
}

bool Button::is_on_button(int mx, int my) {
    
    if (mx >= x && my >= y) {

        if (mx <= x + width && my <= y + height) {

            return true;
        }
    }


    return false;
}

void Button::execute_button() {

    std::cout << value << std::endl;
}


