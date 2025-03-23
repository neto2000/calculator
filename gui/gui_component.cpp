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


    SDL_Texture* img = IMG_LoadTexture(renderer, "../textures/normal_button.png");

    SDL_SetTextureScaleMode(img, SDL_SCALEMODE_NEAREST);

    if (img == NULL) {
        std::cout << "FUCK\n";
    }

    SDL_RenderTexture(renderer, img, NULL, &outline);

    // delete img;

}
