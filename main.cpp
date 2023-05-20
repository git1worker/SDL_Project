
#include "inclSDL.h"
#include "Framework.h"



int main(int argc, char* args[])
{   
    int fps = 60;
    int desiredDelta = 1000 / fps;

    Framework* MainApplicationSDL = nullptr;
    MainApplicationSDL = new Framework();

    

    if (MainApplicationSDL->Init("SDL Window") != true)
        return -1;
    Uint32 lastMS = SDL_GetTicks();
    while (!MainApplicationSDL->GetQuit())
    {
        Uint32 startLoop = SDL_GetTicks();
        MainApplicationSDL->CheckEvents();
        MainApplicationSDL->Update();
        MainApplicationSDL->Render();
        int delta = SDL_GetTicks() - startLoop;

        if (SDL_GetTicks() - lastMS > 1000) {
            float fpsNow = 1000.0f / (delta + 1);
            cout << "FPS: " << fpsNow << endl;
            lastMS = SDL_GetTicks();
        }
            
        if (delta < desiredDelta) {
            SDL_Delay(desiredDelta - delta);
        }

    }

    MainApplicationSDL->CleanRes();
    std::cin.get();
    return 0;

}