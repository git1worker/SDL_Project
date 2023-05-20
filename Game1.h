#pragma once
#include "inclSDL.h"
#include "BasicWindow.h"




class Game1 : public BasicWindow
{
public:
	
	bool Init(const char* title);
	
	void Render();
	
	void Update();

	void CheckEvents();


private:

    void KeySpace();

    void KeyB();

    void KeyEscape();

    void KeyN();

    void KeyQ();

    void KeyI();

    void KeyS();

    void KeyEquals();

    void KeyMinus();

    void SetRandom();

    void MouseButtonDown();

    void MouseButtonUp();

    void MouseMotion();

    void MouseWheel();

};

