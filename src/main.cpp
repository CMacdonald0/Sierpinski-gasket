#include <iostream>
#include <SDL2/SDL.h>

const int WH = 800;
SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

bool init();
void close();

// Initialize SDL and create a window and renderer
bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
        return false;
    }
    gWindow = SDL_CreateWindow("Sierpinksi-gasket", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WH, WH, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        std::cerr << "Failed to create SDL2 window: " << SDL_GetError() << std::endl;
        return false;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr)
    {
        std::cerr << "Failed to create SDL2 renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

// Close renderer and window and quit SDL2
void close()
{
    if (gRenderer != nullptr)
    {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = nullptr;
    }
    if (gWindow != nullptr)
    {
        SDL_DestroyWindow(gWindow);
        gWindow = nullptr;
    }

    SDL_Quit();
}

int main(int argc, char* args[])
{
    if (!init())
        return 1;
    
    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }
        }
        // Clear the window before renderering
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);

        // Update at the end of every frame
        SDL_RenderPresent(gRenderer);
    }
    close();
    return 0;
}
