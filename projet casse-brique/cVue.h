#pragma once
#include "define.h"

using namespace std;

class score;
class cVue
{
	SDL_Window* win;
	SDL_Renderer* rend;
	TTF_Font* police;
	SDL_Color couleur;

public:

	//constructeur
	cVue();
	cVue(int w, int h);

	//destructeur
	~cVue();

	//accesseur
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	//void initBarPlayer();
	//void initWall();
	void cleanRenderer();
	void afficheRenderer();
	void destroyWindow();
	void destroyRenderer();

	void afficheFin(score* game,int w, int h);


};
