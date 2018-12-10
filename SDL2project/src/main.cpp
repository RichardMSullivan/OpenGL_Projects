#include "Game.h"
#include "SDL2/SDL.h"
#include <iostream>

int main( int argc, char* argv[]){//makes sdl work
    
    Game game;
    game.init("Richard Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);

    while(game.running()){

        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();
    return 0; //close program
}

