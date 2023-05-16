
#include "Framework.h"

/// <summary>
/// -----------------------PUBLIC-----------------------
/// </summary>

bool Framework::Init() {

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
    screenHeight = DM.h;

    window = SDL_CreateWindow(
        "SDL Window",
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

    FillGrid();


    return true;
}

bool Framework::GetQuit() {
    return quit;
}

void Framework::CheckEvents() {
    while (SDL_PollEvent(event1)) {

        if (event1->type == SDL_MOUSEBUTTONDOWN)
        {   

            if (event1->button.button == SDL_BUTTON_LEFT)
                MouseDownLeft();

        }

        if (event1->type == SDL_KEYDOWN) {

            if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE)
                KeySpace();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_R)
                KeyR();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_E)
                KeyE();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                KeyEscape();

        }

        if (event1->type == SDL_QUIT)
            quit = true;
    }

}

void Framework::Update() {

}

void Framework::Render() {

}

void Framework::CleanRes() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

/// <summary>
/// -----------------------PRIVATE-----------------------
/// </summary>

void Framework::SetRandom() {
    millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::srand(millisec_since_epoch + counterCallsRandom);

    randInt = millisec_since_epoch * std::rand();
    randInt = randInt / (std::rand() + 1);
    randInt = randInt * std::rand();


    std::srand(randInt);
    ++counterCallsRandom;
}

void Framework::KeySpace() {
    FillGrid();
}

void Framework::KeyEscape() {
    quit = true;
}

void Framework::KeyR() {

    for (int h = 0; h < screenHeight; h += sizeCell) {
        cout << h << endl;
        for (int w = 0; w < screenWidth; w += sizeCell) {

            SetRandom();

            SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

            rect->x = w;
            rect->y = h;

            SDL_RenderFillRect(renderer, rect);

        }
    }
    SDL_RenderPresent(renderer);
}

void Framework::MouseDownLeft()
{
    SDL_GetMouseState(&getX, &getY);

    int quotionerX{ getX / sizeCell };
    int quotionerY{ getY / sizeCell };



    rect->y = quotionerY * sizeCell;
    rect->x = quotionerX * sizeCell;
    
    SetRandom();

    SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
}

void Framework::KeyE() {
    bool exitFor = false;
    for (int h = 0; h < screenHeight; h += sizeCell) {
        cout << h << endl;
        for (int w = 0; w < screenWidth; w += sizeCell) {

            SetRandom();

            SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

            rect->x = w;
            rect->y = h;

            SDL_RenderFillRect(renderer, rect);
            SDL_Delay(5);
            
            SDL_RenderPresent(renderer);
            SDL_PollEvent(event1);
            if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                KeyEscape();
                exitFor = true;
                break;
            }
            else if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE) {
                KeySpace();
                exitFor = true;
                break;
            }
                
        }
        if (exitFor)
            break;
    }
}

void Framework::FillGrid() {

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    for (int h = 0; h < screenHeight; h += sizeCell)
        SDL_RenderDrawLine(renderer, 0, h, screenWidth, h);
    for (int w = 0; w < screenWidth; w += sizeCell) 
        SDL_RenderDrawLine(renderer, w, 0, w, screenHeight);

    SDL_RenderPresent(renderer);
}
