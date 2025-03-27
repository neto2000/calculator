#pragma once

// #include <iostream>
// #include <string>
//
// #include <SDL3/SDL.h>
// #include <SDL3/SDL_main.h>
//
// #include <SDL3_image/SDL_image.h>

#include "gui_component.h"
#include "../logic/key_translator.h"

#include <vector>
#include <SDL3/SDL_scancode.h>



class Display : public GuiComponent{

private:

	std::vector<SDL_Scancode> characters;

	int char_distance;

	int offset_x;
	int offset_y;

	int char_size;

public:
	Display(int cx, int cy, int cwidth, int cheight);	

	void add_char(SDL_Scancode character);

	void remove_last_char();

	void clear();
	
	void render(SDL_Renderer *renderer);

	
};
