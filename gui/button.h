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

	bool is_on_button(int mx, int my);

	void execute_button();
};
