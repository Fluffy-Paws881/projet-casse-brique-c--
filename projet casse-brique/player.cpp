#include "player.h"

player::player(SDL_Rect rect)
{
    rectPlayer = rect;
    stPlayer = state::idle;
}

player::player(int x, int y, int w, int h)
{
    rectPlayer.x = x;
    rectPlayer.y = y;
    rectPlayer.w = w;
    rectPlayer.h = h;
    stPlayer = state::idle;
}

player::~player()
{

}

SDL_Rect player::rectPosPlayer()
{
    return rectPlayer;
}


state player::etatPlayer()
{
    return stPlayer;
}


void player::setPlayerPoseX(int x)
{
    rectPlayer.x = x;
}

void player::setPlayerPoseY(int y)
{
    rectPlayer.y = y;
}

void player::setPlayerState(state etat)
{
    stPlayer = etat;
}

void player::addPlayerPose(int w)
{
    switch (stPlayer)
    {
    case state::left:
        if (rectPlayer.x - 10 > -5)
        {
            rectPlayer.x -= 10;
        }
        break;
    case state::right:
        if (rectPlayer.x + 10 < w + 5)
        {
            rectPlayer.x += 10;
        }
        break;
    case state::idle:
        break;
    }
}

