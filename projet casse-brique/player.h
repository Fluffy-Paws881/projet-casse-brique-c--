#pragma once
#include "define.h"

class player
{
	SDL_Rect rectPlayer;
	state stPlayer;
	


public:

	//constructeur

	player(SDL_Rect rect);
	player(int x, int y, int w, int h);

	//destructeur
	~player();

	//accesseur
	SDL_Rect rectPosPlayer();
	state etatPlayer();


	//mutateur
	void setPlayerPoseX(int x);
	void setPlayerPoseY(int y);
	void setPlayerState(state etat);
	void addPlayerPose(int w);

};
