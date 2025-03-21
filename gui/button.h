#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Button {

private:

	int y;

	int height;
	int width;
	
	SDL_FRect button;
public:

	int x;

	Button(int cx, int cy, int cwidth, int cheight);

	void render(SDL_Renderer *renderer);

	bool is_on_button(int mx, int my);
};
