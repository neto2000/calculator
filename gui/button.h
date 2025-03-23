#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "gui_component.h"

class Button: public GuiComponent {

private:
	

public:
	
	Button(int cvalue, int cx, int cy, int cwidth, int cheight);

	bool is_on_button(int mx, int my);

	void execute_button();
	

	int value;
};
