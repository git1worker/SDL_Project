#pragma once

#include "inclSDL.h"
#include "BasicWindow.h"

class Framework : public BasicWindow
{
public:

    bool Init(const char* title);

    void Update();

    void Render();

    void CheckEvents();

private:

    bool mouseButtonDown = false;
    int sizeCell = 10;
    
    SDL_Rect* rect = new SDL_Rect{ 0, 0, sizeCell, sizeCell };

    void KeySpace();

    void KeyEscape();

    void KeyE();

    void KeyR();

    void MouseButtonDown();

    void FillGrid();

};