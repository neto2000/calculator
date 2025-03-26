#include "button.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>

Button::Button(SDL_Scancode ckey, int cx, int cy, int cwidth, int cheight) : GuiComponent("../textures/normal_button.png", cx, cy, cwidth, cheight) {

    key = ckey;
}

bool Button::is_on_button(int mx, int my) {
    
    if (mx >= x && my >= y) {

        if (mx <= x + width && my <= y + height) {

            return true;
        }
    }


    return false;
}

void Button::execute_button(Display* display) {

    display->add_char(key);
}


void Button::render(SDL_Renderer *renderer) {


    SDL_Texture* img = IMG_LoadTexture(renderer, image_path);

    SDL_SetTextureScaleMode(img, SDL_SCALEMODE_NEAREST);

    if (img == NULL) {
        std::cout << "FUCK\n";
    }

    SDL_RenderTexture(renderer, img, NULL, &outline);

    SDL_DestroyTexture(img);
    
    KeyTranslator kt = KeyTranslator();

    std::string number_path = std::string("../textures/characters/") + kt.translate(key) + ".png";

    SDL_Texture* number = IMG_LoadTexture(renderer, number_path.c_str());

    SDL_SetTextureScaleMode(number, SDL_SCALEMODE_NEAREST);
    
    SDL_RenderTexture(renderer, number, NULL, &outline);

    SDL_DestroyTexture(number);
}
