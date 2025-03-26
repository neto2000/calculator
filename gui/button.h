#pragma once


#include <SDL3/SDL_scancode.h>
#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "gui_component.h"
#include "display.h"

class Button: public GuiComponent {

private:
	

public:
	
	Button(SDL_Scancode ckey, int cx, int cy, int cwidth, int cheight);

	bool is_on_button(int mx, int my);

	void execute_button(Display* display);
	
	void render(SDL_Renderer *renderer);

	SDL_Scancode key;
};
