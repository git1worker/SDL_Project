
#include <SDL.h>
#include "Framework.h"

Framework* MainApplicationSDL = nullptr;

int main(int argc, char* args[])
{

    MainApplicationSDL = new Framework();

    if (MainApplicationSDL->Init() != true)
        return -1;

    while (!MainApplicationSDL->GetQuit())
    {

        MainApplicationSDL->CheckEvents();
        MainApplicationSDL->Update();
        MainApplicationSDL->Render();
    }

    MainApplicationSDL->CleanRes();

    return 0;

}