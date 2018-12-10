#include "SDL2/SDL.h"
#include <iostream>

class Game{

    private:

        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        Game(); //init initialize variables(need to use init to initialize sdl2 stuff
        ~Game(); //destruct

        void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);// initialize sdl
        void reset();//reset varibles
        void handleEvents();//take in user input
        void update();//update all objects
        void render();//draw things to the screen
        void clean();//memory management 

        bool running();//are you running?

};
