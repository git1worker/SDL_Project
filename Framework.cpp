
#include "Framework.h"

/// <summary>
/// -----------------------PUBLIC-----------------------
/// </summary>

bool Framework::Init(const char* title) {

    if (!BasicWindow::Init(title))
        return false;

    FillGrid();

    return true;
}

void Framework::CheckEvents() {
    while (SDL_PollEvent(event1)) {

        if (event1->type == SDL_MOUSEBUTTONDOWN)
            MouseButtonDown();

        else if (event1->type == SDL_MOUSEBUTTONUP)
            MouseButtonUp();

        else if (event1->type == SDL_MOUSEMOTION)
            MouseMotion();

        else if (event1->type == SDL_MOUSEWHEEL)
            MouseWheel();

    

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

/// <summary>
/// -----------------------PRIVATE-----------------------
/// </summary>

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

void Framework::MouseButtonDown() {
    if (event1->button.button == SDL_BUTTON_LEFT) {

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
}

void Framework::KeyE() {

    SetRandom();
    for (int h = 0; h < screenHeight; h += sizeCell) {
        for (int w = 0; w < screenWidth; w += sizeCell) {

            SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

            rect->x = w;
            rect->y = h;

            SDL_RenderFillRect(renderer, rect);
            SDL_Delay(5);
            
            SDL_RenderPresent(renderer);
            SDL_PollEvent(event1);
            if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                KeyEscape();
                return;
            }
            else if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE) {
                KeySpace();
                return;
            }
                
        }
        
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
