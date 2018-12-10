#include "Game.h"



  /////////////////
 //  structors  //
/////////////////

//construct
Game::Game(){

    isRunning = false;
    window = nullptr;
    renderer = nullptr;

std::cout<< "game instance created" <<std::endl;

}
//destruct
Game::~Game(){

std::cout<< "game instance deleted" <<std::endl;

}



  ///////////////
 //  methods  //
///////////////

//initialize sdl
void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL2 subsystems initialized..."<<std::endl;

        window = SDL_CreateWindow(title,xPos,yPos,width,height,flags);
        if(window){
            std::cout<<"SDL2 Window Created..."<<std::endl;
            renderer = SDL_CreateRenderer(window,-1,0);
        }
        if(renderer){
            std::cout<<"SDL2 Renderer Created..."<<std::endl;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            isRunning = true;
        }

    }

}

//reset variables
void Game::reset(){


}
//take in user input
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            std::cout<< event.type <<std::endl;
            break;
    }


}
//update all objects
void Game::update(){


}
//draw things to the screen
void Game::render(){
    SDL_RenderClear(renderer);
    //this is where we render stuff
    SDL_RenderPresent(renderer);

}
//memory management
void Game::clean(){
    SDL_DestroyRenderer(renderer);
    std::cout<<"SDL2 Renderer Destroyed..."<<std::endl;
    SDL_DestroyWindow(window);
    std::cout<<"SDL2 Window Destroyed..."<<std::endl;
    SDL_Quit();
    std::cout<<"SDL2 Subsystems Destroyed..."<<std::endl;
    std::cout<<"\n Game Cleaned..."<<std::endl;

}

bool Game::running(){//are you running?

    return this->isRunning;
}
