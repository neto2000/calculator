#include "button.h"



Button::Button(int cx, int cy, int cwidth, int cheight) {

    x = cx;
    y = cy;
    width = cwidth;
    height = cheight;




    button.x = x;
    button.y = y;

    button.w = width;
    button.h = height;


}

void Button::render(SDL_Renderer *renderer) {


    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);  /* red, full alpha */
    SDL_RenderRect(renderer, &button);


    // SDL_RenderPresent(renderer);
}


bool Button::is_on_button(int mx, int my) {
    
    if (mx >= x && my >= y) {

        if (mx <= x + width && my <= y + height) {

            return true;
        }
    }


    return false;
}

