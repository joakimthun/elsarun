#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "game.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 1;
    }

    auto img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags))
    {
        std::cout << "SDL_image could not be initialized! IMG_GetError:" << std::endl << IMG_GetError() << std::endl;
        return 1;
    }

    auto game = std::make_unique<elsa::Game>();
    game->init();
    game->run();

    SDL_Quit();

    return 0;
}