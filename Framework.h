
#pragma once
#include <SDL.h>
#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;


class Framework
{
public:

    bool Init();

    void CheckEvents();

    bool GetQuit();

    void Update();

    void Render();

    void CleanRes();

private:

    int32_t flags = SDL_WINDOW_SHOWN;
    int width = 1200;
    int height = 800;
    bool mouseButtonDown = false;
    int getX;
    int getY;
    int sizeCell = 10;
    int screenWidth;
    int screenHeight;
    int counterCallsRandom = 0;

    SDL_Event* event1 = new SDL_Event();

    bool quit = false;

    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_Rect* rect = new SDL_Rect{ 0, 0, sizeCell, sizeCell };
    SDL_DisplayMode DM;

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