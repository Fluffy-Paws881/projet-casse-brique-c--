#include "bric.h"

/*bric::bric(int wBric, int hBric, int x, int y)
{
	rectBric.x = wBric;
	rectBric.y = hBric;
	rectBric.w = wBric;
	rectBric.h = hBric;

	isActive = true;

}*/

void bric::initPos(int wBric, int hBric, int x, int y)
{
	rectBric.x = x;
	rectBric.y = y;
	rectBric.w = wBric;
	rectBric.h = hBric;

	rectMid.x = x;
	rectMid.y = y + hBric / 3;
	rectMid.w = wBric;
	rectMid.h = hBric / 3;

	isActive = true;
}

void bric::setState(bool b)
{
	isActive = b;
}



SDL_Rect bric::getRect()
{
	return rectBric;
}

SDL_Rect bric::getRectMid()
{
	return rectMid;
}

bool bric::getState()
{
	return isActive;
}
