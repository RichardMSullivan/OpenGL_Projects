#include "SDL2/SDL.h"
#include <iostream>

//the first thing you have to do is decide the screen size
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;
int main(int argc, char* argv[]){

    //now we will make our wundow
    SDL_Window* window = NULL;

    //the surface which we display in the window needs to be created
    SDL_Surface* screenSurface = NULL;

    //now that the screen and surface is created we need to initialize sdl

    if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
        std::cout<<"sdl could not be initialized"<<std::endl;
    }   
    else{
        //this is how you create a window
        window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL){
            std::cout<<"failed to create window"<<std::endl;
        }
        else{
            //this is how you make the surface
            screenSurface = SDL_GetWindowSurface( window );
            
            //thi is how we set the whole screen to a color
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB(screenSurface ->format,0,0,0));

            //updating the surface to be displayed in the window
            SDL_UpdateWindowSurface( window );

            //waiting two seconds
            SDL_Delay( 20000 );
        }
    }
    //how to destroy the window
    SDL_DestroyWindow( window );
    //how to quit sdl
    SDL_Quit();
    
    //end of program
    return 0;
}


