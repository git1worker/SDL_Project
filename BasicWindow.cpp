#include "BasicWindow.h"

// PUBLIC

bool BasicWindow::Init(const char* title) {

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

    return true;
}

void BasicWindow::Update()
{
}

void BasicWindow::Render()
{
}

void BasicWindow::CheckEvents() {
    while (SDL_PollEvent(event1)) {

        if (event1->type == SDL_MOUSEBUTTONDOWN)
            MouseButtonDown();

        else if (event1->type == SDL_MOUSEBUTTONUP)
            MouseButtonUp();

        else if (event1->type == SDL_MOUSEMOTION)
            MouseMotion();

        else if (event1->type == SDL_MOUSEWHEEL)
            MouseWheel();


        else if (event1->type == SDL_KEYDOWN) {

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

            else if (event1->key.keysym.scancode == SDL_SCANCODE_EQUALS)
                KeyEquals();

            else if (event1->key.keysym.scancode == SDL_SCANCODE_MINUS)
                KeyMinus();

        }

        if (event1->type == SDL_QUIT)
            quit = true;
    }

}

bool BasicWindow::GetQuit() {
    return quit;
}

void BasicWindow::CleanRes() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// PRIVATE

void BasicWindow::SetRandom() {
    millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::srand((unsigned int)(millisec_since_epoch + counterCallsRandom));

    randInt = millisec_since_epoch * std::rand();
    randInt = randInt / (std::rand() + 1);
    randInt = randInt * std::rand();

    std::srand((unsigned int)randInt);
    ++counterCallsRandom;
}

void BasicWindow::KeySpace()
{
}

void BasicWindow::KeyB()
{
}

void BasicWindow::KeyEscape()
{
}

void BasicWindow::KeyN()
{
}

void BasicWindow::KeyQ()
{
}

void BasicWindow::KeyI()
{
}

void BasicWindow::KeyS()
{
}

void BasicWindow::KeyEquals()
{
}

void BasicWindow::KeyMinus()
{
}

void BasicWindow::MouseButtonDown()
{
}

void BasicWindow::MouseButtonUp()
{
}

void BasicWindow::MouseMotion()
{
}

void BasicWindow::MouseWheel()
{
}

