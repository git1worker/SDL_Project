
#include "inclSDL.h"


SortArray* MainApplicationSDL = nullptr;

int main(int argc, char* args[])
{   
    int fps = 60;
    int desiredDelta = 1000 / fps;

    MainApplicationSDL = new SortArray();

    if (MainApplicationSDL->Init("SDL Window") != true)
        return -1;

    while (!MainApplicationSDL->GetQuit())
    {
        int startLoop = SDL_GetTicks();
        MainApplicationSDL->CheckEvents();
        MainApplicationSDL->Update();
        MainApplicationSDL->Render();
        int delta = SDL_GetTicks() - startLoop;
        if (delta < desiredDelta) {
            SDL_Delay(desiredDelta - delta);
        }
    }
    

    MainApplicationSDL->CleanRes();

    return 0;

}