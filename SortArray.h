#pragma once
#include "inclSDL.h"
#include "BasicWindow.h"



class SortArray : public BasicWindow {

public:

    bool Init(const char* title);

    void Update();

    void Render();

    void CheckEvents();

private:

    int* arr = nullptr;
    float scale = 1;
    int sizeArray = 300;
    int widthRow = (int)(3 * scale);
    bool lButtonIsDown = false;
    signed int xMovement = 0;
    signed int yMovement = 0;
    

    void FillRect(int x, int y, int w, int h);

    int Partition(int a[], int start, int end);

    void Quicksort(int a[], int start, int end);

    int findSmallestPosition(int list[], int startPosition, int listLength);

    void GeneratingArray();

    void ClearScreen();

    void PrintArray();

    void VizualizationSortingArray(const char* method);

    void Swap(int* xp, int* yp);


    void KeySpace();

    void KeyB();

    void KeyEscape();

    void KeyN();

    void KeyQ();

    void KeyI();

    void KeyS();

    void KeyEquals();

    void KeyMinus();

    void MouseButtonDown();

    void MouseButtonUp();

    void MouseMotion();

    void MouseWheel();
};