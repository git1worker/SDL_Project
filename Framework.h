
#pragma once
#include "inclSDL.h"






class Framework
{
public:

    bool Init(const char* title);

    bool GetQuit();

    void Update();

    void Render();

    void CleanRes();

    void CheckEvents();

private:

    int width = 1200;
    int height = 800;
    bool mouseButtonDown = false;
    int getX;
    int getY;
    int sizeCell = 10;
    int counterCallsRandom = 0;
    int32_t flags = SDL_WINDOW_SHOWN;
    int screenWidth;
    int screenHeight;
    bool quit = false;

    SDL_DisplayMode DM;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_Event* event1 = new SDL_Event();
    SDL_Rect* rect = new SDL_Rect{ 0, 0, sizeCell, sizeCell };
    
    unsigned long int randInt;
    unsigned long int millisec_since_epoch;

    void SetRandom();

    void KeySpace();

    void KeyEscape();

    void KeyE();

    void KeyR();

    void MouseDownLeft();

    void FillGrid();

};