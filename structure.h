#pragma once

#include <vector>
#include "gui/button.h"

class Structure {

private:
	
	std::vector<Button*>* buttons;

public:

	Structure();

	std::vector<Button*>* get_buttons();	

};
