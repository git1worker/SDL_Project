#include "Game1.h"

bool Game1::Init(const char* title) {
	
	if (!BasicWindow::Init(title)) {
		return false;
	}



	return true;

}

void Game1::CheckEvents() {
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

// PRIVATE

void Game1::KeySpace()
{
}

void Game1::KeyB()
{
}

void Game1::KeyEscape()
{
}

void Game1::KeyN()
{
}

void Game1::KeyQ()
{
}

void Game1::KeyI()
{
}

void Game1::KeyS()
{
}

void Game1::KeyEquals()
{
}

void Game1::KeyMinus()
{
}

void Game1::MouseButtonDown()
{
}

void Game1::MouseButtonUp()
{
}

void Game1::MouseMotion()
{
}

void Game1::MouseWheel()
{
}

