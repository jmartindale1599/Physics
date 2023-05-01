
#include <iostream>

#include <include/SDL.h>

#include <glm/glm.hpp>

int main(int argc, char* argv[]) {

    SDL_Window* window = NULL;
    
    SDL_Surface* screenSurface = NULL;

    glm::ivec2 screen{ 800, 600 };

    // Initialize SDL
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        
        return 1;
    
    }

    // Create window
    
    window = SDL_CreateWindow(
    
        "SDL2 Window",
        
        SDL_WINDOWPOS_UNDEFINED,
        
        SDL_WINDOWPOS_UNDEFINED,
        
        screen.x,
        
        screen.y,
        
        SDL_WINDOW_SHOWN
    
    );

    if (window == NULL){

        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

        return 1;
    
    }

    // Get the window's surface
    
    screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface with a color (in this case, white)
    
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    
    SDL_UpdateWindowSurface(window);

    // Wait for a few seconds
    
    SDL_Delay(3000);

    // Destroy the window
    
    SDL_DestroyWindow(window);

    // Quit SDL
    
    SDL_Quit();

    return 0;

}
