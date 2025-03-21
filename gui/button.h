#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Button {

private:

	std::string m_msg;

public:

	Button(std::string msg);

	
	void print();

};
