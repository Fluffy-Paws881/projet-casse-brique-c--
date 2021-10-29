#include "cVue.h"

cVue::cVue()
{
    win = nullptr;
    rend = nullptr;
    police = nullptr;
    couleur = { 255, 255, 255 }; 
}

cVue::cVue(int w, int h)
{
    win = SDL_CreateWindow("GAME", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w, h, 0);

    couleur = { 255, 255, 255 };

    // creation du renderer
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    police = TTF_OpenFont("../font/BAUHS93.ttf", 65);
    if (police == nullptr)
    {
        fprintf(stderr, "Erreur %s\n", SDL_GetError());
    }
}

cVue::~cVue()
{
}

SDL_Renderer* cVue::getRenderer()
{
    return rend;
}

SDL_Window* cVue::getWindow()
{
    return win;
}

void cVue::cleanRenderer()
{
    SDL_RenderClear(rend);
}

void cVue::afficheRenderer()
{
    SDL_RenderPresent(rend);
}

void cVue::destroyWindow()
{
    SDL_DestroyWindow(win);
}

void cVue::destroyRenderer()
{
    SDL_DestroyRenderer(rend);
}

void cVue::afficheFin(score* game, int w, int h)
{
    SDL_Surface* surfTexte = NULL;
	char cScr[100] = "";
	SDL_Rect posi = {20,h/2,600,50 };
	
    if (game->verifVictoire())
    {
        sprintf_s(cScr, "félicitations joueur, vous remportez cette partie avec un score de %d points!", game->getnbPoint());
    }
    else if (game->getnbLife() <= 0)
    {
        sprintf_s(cScr, "dommage, vous avez perdu cette partie avec un score de %d points!", game->getnbPoint());
    }
	
	surfTexte = TTF_RenderText_Blended(police, cScr, couleur);

	SDL_Texture* text = SDL_CreateTextureFromSurface(rend, surfTexte);
	SDL_FreeSurface(surfTexte);
	
	SDL_RenderCopy(rend, text, NULL, &posi);

    this->afficheRenderer();
}
