
#include "Framework.h"


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

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);


    return true;
}

bool Framework::GetQuit() {
    return quit;
}

void Framework::SetRandom() {
    millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::srand(millisec_since_epoch + counterCallsRandom);

    randInt = millisec_since_epoch * std::rand();
    randInt = randInt / (std::rand() + 1);
    randInt = randInt * std::rand();


    std::srand(randInt);
    ++counterCallsRandom;
}

void Framework::CheckEvents() {
    while (SDL_PollEvent(event1)) {

        if (event1->type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&getX, &getY);
            rect->x = getX;
            rect->y = getY;

            SetRandom();

            SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);
            SDL_RenderFillRect(renderer, rect);
            SDL_RenderPresent(renderer);
            

        }

        if (event1->type == SDL_KEYDOWN) {

            if (event1->key.keysym.scancode == SDL_SCANCODE_SPACE)
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }

            else if (event1->key.keysym.scancode == SDL_SCANCODE_R) {
                for (int h = 0; h < screenHeight; h += sizeRect) {
                    cout << h << endl;
                    for (int w = 0; w < screenWidth; w += sizeRect) {

                        SetRandom();

                        SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

                        rect->x = w;
                        rect->y = h;

                        SDL_RenderFillRect(renderer, rect);


                    }
                }
                SDL_RenderPresent(renderer);
            }

            else if (event1->key.keysym.scancode == SDL_SCANCODE_E) {
                for (int h = 0; h < screenHeight; h += sizeRect) {
                    cout << h << endl;
                    for (int w = 0; w < screenWidth; w += sizeRect) {

                        SetRandom();

                        SDL_SetRenderDrawColor(renderer, std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);

                        rect->x = w;
                        rect->y = h;

                        SDL_RenderFillRect(renderer, rect);
                        SDL_Delay(5);
                        SDL_RenderPresent(renderer);

                    }
                }
               
            }
            else if (event1->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                quit = true;
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