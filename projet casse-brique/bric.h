#pragma once
#include "define.h"

class bric
{
	SDL_Rect rectBric;
	SDL_Rect rectMid;
	bool isActive;

public:

	//bric(int wBric, int hBric, int x, int y);

	void initPos(int wBric, int hBric, int x, int y);
	void setState(bool b);
	

	SDL_Rect getRect();
	SDL_Rect getRectMid();
	bool getState();
};
