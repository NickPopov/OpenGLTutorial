#pragma once

#include <string>

#include "SDL2\SDL.h"

class Display
{
public:
	Display(int width, int height, std::string& title);
	virtual ~Display();

	void Update();
	void Clear(float r, float g, float b, float a);
	bool IsClosed();
	
private:
	SDL_Window *m_window;
	SDL_GLContext m_glContext;

	bool m_isClosed;

	//Display &Display::operator=(const Display& display) {};
	//Display(const Display& display) {};
};

