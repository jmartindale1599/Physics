
#include <iostream>

#include <include/SDL.h>

#include <glm/glm.hpp>

int main(int argc, char* argv[]) {

    SDL_Window* window = NULL;
    
    SDL_Surface* screenSurface = NULL;

    glm::ivec2 screen{ 800, 600 };

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        
        return 1;
    
        
        SDL_WINDOW_SHOWN
    
    );

    if (window == NULL){

        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    
    }

    return 0;

}
