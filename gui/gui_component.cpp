#include "gui_component.h"

GuiComponent::GuiComponent(const char* cimage_path, int cx, int cy, int cwidth, int cheight) {

    x = cx;
    y = cy;
    width = cwidth;
    height = cheight;

    image_path = cimage_path; 


    outline.x = x;
    outline.y = y;

    outline.w = width;
    outline.h = height;
}


void GuiComponent::render(SDL_Renderer *renderer) {


    SDL_Texture* img = IMG_LoadTexture(renderer, image_path);

    SDL_SetTextureScaleMode(img, SDL_SCALEMODE_NEAREST);

    if (img == NULL) {
        std::cout << "FUCK\n";
    }

    SDL_RenderTexture(renderer, img, NULL, &outline);

    // delete img;

}
