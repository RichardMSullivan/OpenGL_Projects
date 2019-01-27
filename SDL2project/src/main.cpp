#include "SDL2/SDL.h"
#include <iostream>

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]){
    if( !init() ){
        std::cout<<"error init()"<<std::endl;
    }
    else
    {
        if( !loadMedia() ){
            std::cout<<"error loadMedia()"<<std::endl;
        }
        else{
            SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(10000);
        }
    }
    close();
    return 0;    
}

bool init(){
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        std::cout<<"failed to init video"<<std::endl;
        success = false;
    }
    else{
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN );
        if( gWindow == NULL ){
            std::cout<<"error creating gWindow"<<std::endl;
            success = false;
        }
        else{
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}

bool loadMedia(){
    bool success = true;
    gHelloWorld = SDL_LoadBMP("./assets/turtle.bmp");
    if(gHelloWorld == NULL){
        std::cout<<"unable to load image"<<std::endl;
        success = false;
    }

    return success;
}

void close(){
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}
