#define SDL_MAIN_USE_CALLBACKS 1

#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "gui/button.h"


static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;



#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {


    SDL_SetAppMetadata("Example Renderer Rectangles", "1.0", "com.example.renderer-rectangles");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/rectangles", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }



    Button test = Button("Hello Button!");

    test.print();

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }



    return SDL_APP_CONTINUE;  /* carry on with the program! */
}


SDL_AppResult SDL_AppIterate(void *appstate) {
    

    SDL_FRect rects[16];

    /* Let's draw a single rectangle (square, really). */
    rects[0].x = rects[0].y = 100;
    rects[0].w = rects[0].h = 100 + (100 * 1);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);  /* red, full alpha */
    SDL_RenderRect(renderer, &rects[0]);


    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
}
