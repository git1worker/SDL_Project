#pragma once
#include "inclSDL.h"

using std::cout;
using std::endl;

class SortArray {

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
    int32_t flags = SDL_WINDOW_SHOWN;
    int screenWidth;
    int screenHeight;
    bool quit = false;
    int counterCallsRandom = 0;
    int sizeArray;
    int* arr = nullptr;
    int widthRow = 1;
    

    SDL_DisplayMode DM;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_Event* event1 = new SDL_Event();
    
    unsigned long int randInt;
    unsigned long int millisec_since_epoch;

    void FillRect(int x, int y, int w, int h);

    void SetRandom();

    int  Partition(int a[], int start, int end);

    void Quicksort(int a[], int start, int end);

    int findSmallestPosition(int list[], int startPosition, int listLength);

    void GeneratingArray();

    void ClearScreen();

    void PrintArray();

    void VizualizationSortingArray(const char* method);

    void KeySpace();

    void KeyB();

    void KeyEscape();

    void Swap(int* xp, int* yp);

    void KeyN();

    void KeyQ();

    void KeyI();

    void KeyS();
};