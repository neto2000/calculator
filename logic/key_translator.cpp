#include "key_translator.h"
#include <SDL3/SDL_scancode.h>

KeyTranslator::KeyTranslator() {

    dict = {
        {SDL_SCANCODE_1, "1"},
        {SDL_SCANCODE_2, "2"},
        {SDL_SCANCODE_3, "3"},
        {SDL_SCANCODE_4, "4"},
        {SDL_SCANCODE_5, "5"},
        {SDL_SCANCODE_6, "6"},
        {SDL_SCANCODE_7, "7"},
        {SDL_SCANCODE_8, "8"},
        {SDL_SCANCODE_9, "9"},
        {SDL_SCANCODE_0, "0"}
    };
}


std::string KeyTranslator::translate(SDL_Scancode key) {

    return dict[key];
}
