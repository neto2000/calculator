#pragma once

#include <vector>
#include "gui/button.h"
#include "gui/display.h"

class Structure {

private:
	
	std::vector<Button*>* buttons;

	Display* display;

public:

	Structure();

	std::vector<Button*>* get_buttons();	

	Display* get_display();

};
