
#include "display.h"
#include <SDL3/SDL_scancode.h>

Display::Display(int cx, int cy, int cwidth, int cheight) : GuiComponent("../textures/normal_button.png", cx, cy, cwidth, cheight) {
    

    char_distance = -4;

    char_size = 24;

    offset_x = offset_y = 20;

}

void Display::add_char(SDL_Scancode character) {

    characters.push_back(character);
}

void Display::remove_last_char() {

    if (characters.size() < 1) {

        return;
    }

    characters.pop_back();

}

void Display::clear() {

    characters.clear();
}

void Display::render(SDL_Renderer *renderer) {


    SDL_Texture* background = IMG_LoadTexture(renderer, image_path);

    SDL_SetTextureScaleMode(background , SDL_SCALEMODE_NEAREST);

    SDL_RenderTexture(renderer, background , NULL, &outline);

    SDL_DestroyTexture(background);

    int char_x = x + offset_x; 
    int char_y = y + offset_y;

    int char_width = (width - offset_x) / (char_size + char_distance);




    int start_char = 0;

    if (characters.size() > char_width) {

        start_char = characters.size() - char_width;
    }

    for (int i = start_char; i < characters.size(); i++) {

        SDL_FRect box;

        box.x = char_x;
        box.y = char_y;

        box.w = box.h = char_size;

        KeyTranslator translator = KeyTranslator();

        std::string char_tex_path = std::string("../textures/characters/") + translator.translate(characters.at(i)) + ".png";


        SDL_Texture* char_tex = IMG_LoadTexture(renderer, char_tex_path.c_str());

        SDL_SetTextureScaleMode(char_tex , SDL_SCALEMODE_NEAREST);

        SDL_RenderTexture(renderer, char_tex , NULL, &box);

        SDL_DestroyTexture(char_tex);


        char_x = char_x + char_size + char_distance;
    }

}
