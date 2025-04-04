#pragma once


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

class GuiComponent {

private:
	
	
public:
	
	int x;
	int y;

	int height;
	int width;

	SDL_FRect outline;

	const char* image_path;

	GuiComponent(const char* cimage_path, int cx, int cy, int cwidth, int cheight);

	void render(SDL_Renderer *renderer);

};

