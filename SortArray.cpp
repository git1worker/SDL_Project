
#include "SortArray.h"

bool SortArray::Init(const char* title) {

    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        cout << "Initialization completed successfully" << endl;
    }
    else
    {
        cout << "Initialization failed with error: " << SDL_GetError() << endl;
        return false;
    }

    SDL_GetCurrentDisplayMode(0, &DM);
    screenWidth = DM.w;
    screenHeight = DM.h - 60;

    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screenWidth, screenHeight,
        flags
    );

    if (window == 0)
    {
        cout << "Window creation failed with error: " << SDL_GetError() << endl;
        return false;
    }
    else
        cout << "Window creation completed succesfully" << endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == 0)
    {
        cout << "Renderer creation faled with error: " << SDL_GetError() << endl;
        return false;
    }
    else
        cout << "Renderer creation completed succesfully" << endl;
    
    /*FillRect(0, 100, 2, screenHeight - 100 - 100);
    FillRect(screenWidth - 2, 100, 2, screenHeight - 100 - 100);*/

    sizeArray = 300;
    widthRow = 3;

    KeyN();

    return true;
}

void SortArray::ClearScreen() {
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


    FillRect(0, 100, screenWidth, 2);
    FillRect(0, screenHeight - 100, screenWidth, 2);
    FillRect(0, screenHeight / 2, screenWidth, 2);
    SDL_SetRenderDrawColor(renderer, 22, 130, 0, 255);
}

void SortArray::PrintArray() {

    

    int DistBetween = (screenWidth - widthRow * sizeArray) / (sizeArray + 1);

    int voidDist = screenWidth - (widthRow * sizeArray + DistBetween * sizeArray);
    
    int x = voidDist / 2;

    for (int i{ 0 }; i < sizeArray; ++i) {
        x += DistBetween;
        if (x > screenWidth) break;

        FillRect(x, screenHeight - 100 - arr[i], widthRow, arr[i]);
        x += widthRow;
    }
    SDL_RenderPresent(renderer);
    ClearScreen();
}

void SortArray::GeneratingArray() {

    arr = new int[sizeArray];
    SetRandom();
    for (int i{ 0 }; i < this->sizeArray; ++i) {
        this->arr[i] = std::rand() % (screenHeight - 100 - 100) + 1;
    }
    
}

void SortArray::Swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    PrintArray();
    
}

int SortArray::Partition(int* a, int start, int end)
{
    // ¬ыбираем крайний правый элемент в качестве опорного элемента массива
    int pivot = a[end];

    // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
    // равные элементы могут идти в любом направлении
    int pIndex = start;

    // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
    // увеличиваетс€, и этот элемент будет помещен перед опорной точкой.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            Swap(&a[i], &a[pIndex]);
            
            pIndex++;
        }
    }

    // помен€ть местами `pIndex` с пивотом
    Swap(&a[pIndex], &a[end]);
    
    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}

// ѕроцедура быстрой сортировки
void SortArray::Quicksort(int* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }

    // переставить элементы по оси
    int pivot = Partition(a, start, end);

    // повтор€ем подмассив, содержащий элементы, меньшие опорной точки
    Quicksort(a, start, pivot - 1);

    // повтор€ем подмассив, содержащий элементы, превышающие точку опоры
    Quicksort(a, pivot + 1, end);
}


void SortArray::VizualizationSortingArray(const char* method) {
    if (method == "bubble") {
        int i, j;
        for (i = 0; i < sizeArray - 1; i++)        
            for (j = 0; j < sizeArray - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    Swap(&arr[j], &arr[j + 1]);
                    SDL_PollEvent(event1);
                    if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE) {
                        KeySpace();
                        return;
                    }
                    else if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                        KeyEscape();
                        return;
                    }
                            
                }
                
    }
    else if (method == "quicksort")
        Quicksort(arr, 0, sizeArray - 1);
                
    else if (method == "insert") {
        for (int i = 1; i < sizeArray; ++i)
        {
            int j = i - 1;
            while (j >= 0 && arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                
                --j;

            }
        }
    }
    else if(method == "select") {
        for (int i = 0; i < sizeArray; i++)
        {
            int smallestPosition = findSmallestPosition(arr, i, sizeArray);
            Swap(&arr[i], &arr[smallestPosition]);
        }
    }
}

int SortArray::findSmallestPosition(int list[], int startPosition, int listLength)
{
    int smallestPosition = startPosition;

    for (int i = startPosition; i < listLength; i++)
    {
        if (list[i] < list[smallestPosition])
            smallestPosition = i;
    }
    return smallestPosition;
}

void SortArray::SetRandom() {
    millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::srand(millisec_since_epoch + counterCallsRandom);

    randInt = millisec_since_epoch * std::rand();
    randInt = randInt / (std::rand() + 1);
    randInt = randInt * std::rand();

    std::srand(randInt);
    ++counterCallsRandom;
}

void SortArray::FillRect(int x, int y, int w, int h) {
    SDL_Rect line;
    line.x = x;
    line.y = y;
    line.w = w;
    line.h = h;
    SDL_RenderFillRect(renderer, &line);
}

bool SortArray::GetQuit() {
    return quit;
}

void SortArray::CheckEvents() {
    while (SDL_PollEvent(event1)) {

        if (event1->type == SDL_MOUSEBUTTONDOWN)
        {


        }

        if (event1->type == SDL_KEYDOWN) {

            if (event1->key.keysym.scancode == SDL_SCANCODE_B)
                KeyB();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_Q)
                KeyQ();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE)
                KeySpace();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                KeyEscape();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_N)
                KeyN();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_I)
                KeyI();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_S)
                KeyS();
        }

        if (event1->type == SDL_QUIT)
            quit = true;
    }

}

void SortArray::Update() {

}

void SortArray::Render() {

}

void SortArray::CleanRes() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SortArray::KeySpace() {
    ClearScreen();
    SDL_RenderPresent(renderer);
    PrintArray();
}

void SortArray::KeyB() {
    VizualizationSortingArray("bubble");
}

void SortArray::KeyEscape() {
    quit = true;
}

void SortArray::KeyN() {
    ClearScreen();
    GeneratingArray();
    PrintArray();
}

void SortArray::KeyQ() {
    VizualizationSortingArray("quicksort");
}

void SortArray::KeyI() {
    VizualizationSortingArray("insert");
}

void SortArray::KeyS() {
    VizualizationSortingArray("select");
}