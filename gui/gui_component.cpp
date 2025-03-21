#include "gui_component.h"

GuiComponent::GuiComponent(int cx, int cy, int cwidth, int cheight) {

    x = cx;
    y = cy;
    width = cwidth;
    height = cheight;




    outline.x = x;
    outline.y = y;

    outline.w = width;
    outline.h = height;
}


void GuiComponent::render(SDL_Renderer *renderer) {


    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);  /* red, full alpha */
    SDL_RenderRect(renderer, &outline);

}
