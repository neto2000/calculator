#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class GuiComponent {

private:

	
public:
	
	int x;
	int y;

	int height;
	int width;

	SDL_FRect outline;

	GuiComponent(int cx, int cy, int cwidth, int cheight);

	void render(SDL_Renderer *renderer);

};

