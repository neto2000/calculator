#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "gui_component.h"

class Button: public GuiComponent {

private:

public:

	using GuiComponent::GuiComponent;
	// Button(int cx, int cy, int cwidth, int cheight);

	// void render(SDL_Renderer *renderer);

	bool is_on_button(int mx, int my);
};
