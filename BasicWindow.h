#pragma once
#include "inclSDL.h"



class BasicWindow
{
public:

	bool Init(const char* title);

    void Update();

    void Render();

    void CheckEvents();

    bool GetQuit();

    void CleanRes();

protected:

    SDL_DisplayMode DM;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_Event* event1 = new SDL_Event();

    Uint64 counterCallsRandom = 0;
    int32_t flags = SDL_WINDOW_SHOWN;
    int screenWidth;
    int screenHeight;
    bool quit = false;
    int getX;
    int getY;
    Uint64 randInt;
    Uint64 millisec_since_epoch;

    void KeySpace();

    void KeyB();

    void KeyEscape();

    void KeyN();

    void KeyQ();

    void KeyI();

    void KeyS();

    void KeyEquals();

    void KeyMinus();

    void SetRandom();

    void MouseButtonDown();

    void MouseButtonUp();

    void MouseMotion();

    void MouseWheel();
    
};

