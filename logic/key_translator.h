#pragma once

#include <string>
#include <map>

#include <SDL3/SDL_scancode.h>


class KeyTranslator {

private:

	std::map<SDL_Scancode, std::string> dict;

public:

	KeyTranslator();

	std::string translate(SDL_Scancode key);

};
