#include <SDL3/SDL_events.h>
#include <ostream>
#define SDL_MAIN_USE_CALLBACKS 1

#include <iostream>
#include <string>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "gui/button.h"
#include "structure.h"
#include "gui/display.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


namespace {
    struct AppState {
        
        SDL_Window *window{nullptr};
        SDL_Renderer *renderer{nullptr};
       
        Display *display{nullptr};
        
        std::vector<Button*>* buttons{nullptr};
    };
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    

    *appstate = new AppState;
    AppState& state = *static_cast<AppState*>(*appstate);

    
    SDL_SetAppMetadata("Example Renderer Rectangles", "1.0", "com.example.renderer-rectangles");


    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/rectangles", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &state.window, &state.renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }




    Structure structure = Structure();

    state.buttons = structure.get_buttons();


    state.display = structure.get_display();


    return SDL_APP_CONTINUE;  /* carry on with the program! */
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{

    AppState& state = *static_cast<AppState*>(appstate);

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {

        float x,y;

        SDL_GetMouseState(&x, &y);

            
        for (int i = 0; i < state.buttons->size(); i++) {

            if (state.buttons->at(i)->is_on_button(static_cast<int>(x), static_cast<int>(y))) {

                state.buttons->at(i)->execute_button();
            }
        }
    }

    if (event->type == SDL_EVENT_KEY_DOWN) {

        if (event->key.scancode == SDL_SCANCODE_1) {

            std::cout << "one\n";
        }

        state.display->add_char(event->key.scancode);

    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}


SDL_AppResult SDL_AppIterate(void *appstate) {
    
    AppState& state = *static_cast<AppState*>(appstate);
    

    for (int i = 0; i < state.buttons->size(); i++) {

        state.buttons->at(i)->render(state.renderer);
    }

    state.display->render(state.renderer);

    SDL_RenderPresent(state.renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    AppState& state = *static_cast<AppState*>(appstate);


    for (int i = 0; i < state.buttons->size(); i++) {

        delete state.buttons->at(i);
    }

    delete state.buttons;

    delete state.display;

    /* SDL will clean up the window/renderer for us. */
}
