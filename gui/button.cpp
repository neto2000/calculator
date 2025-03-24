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


void Button::render(SDL_Renderer *renderer) {


    SDL_Texture* img = IMG_LoadTexture(renderer, image_path);

    SDL_SetTextureScaleMode(img, SDL_SCALEMODE_NEAREST);

    if (img == NULL) {
        std::cout << "FUCK\n";
    }

    SDL_RenderTexture(renderer, img, NULL, &outline);

    // delete img;
    //

    std::string number_path = std::string("../textures/characters/") + std::to_string(value) + ".png";

    SDL_Texture* number = IMG_LoadTexture(renderer, number_path.c_str());

    SDL_SetTextureScaleMode(number, SDL_SCALEMODE_NEAREST);
    
    SDL_RenderTexture(renderer, number, NULL, &outline);
}
