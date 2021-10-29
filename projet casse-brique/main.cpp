#include "define.h"


int main(int argc, char* argv[])
{
    // retourne une erreur si probleme lors de l'initialisation 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL: %s\n" << SDL_GetError();
    }
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
   
    const int nbBrique = WIDTH / WBRIQUE - 2;

    score game(NBLIFE);
    cVue rendu(WIDTH, HEIGHT);
    player joueur(WIDTH/2 -50, HEIGHT - 20, 100,20);
    balle ballePlayer(WIDTH / 2, HEIGHT / 2, 10, 10, 0, 5);
    
  
    bric tabBric[LIGNEBRIQUE][nbBrique];

    //initialisation du tableau de brique
    int x = WBRIQUE;
    int y = HBRIQUE;
    for (int l = 0; l < LIGNEBRIQUE ; l++)
    {
        for (int c = 0; c < nbBrique - 1; c++)
        {
            tabBric[l][c].initPos(WBRIQUE, HBRIQUE, x, y);
            tabBric[l][c].setState(true);
            x += WBRIQUE + 2;
            game.addBrique();
        }
        x = WBRIQUE;
        y += HBRIQUE + 2;
    }

    
    
    

    // controls annimation loop
    int close = 0;

    while (!close && !game.verifVictoire() && game.getnbLife() > 0) {
        SDL_Event event;

        //verification de la sortie de la balle
        ballePlayer.verifZone(&game, WIDTH, HEIGHT, &joueur);

        //deplacement de la balle   
        ballePlayer.deplacementBalle(HEIGHT);

        //verification si colision avec un des joueurs et si oui modification du vecteur de deplacement
        ballePlayer.rebondPlayer(joueur.rectPosPlayer());

        //verification si colision avec un mur et si oui modification du vecteur de deplacement
        ballePlayer.rebondMural(WIDTH);

        //verification collisions avec les briques
        for (int l = 0; l < LIGNEBRIQUE; l++)
        {
            for (int c = 0; c < nbBrique; c++)
            {
                ballePlayer.rebondBric(&tabBric[l][c], &game);
            }

        }


        // Events management
        while (SDL_PollEvent(&event))
        {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_q:
                    joueur.setPlayerState(state::left);
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    joueur.setPlayerState(state::right);
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                case SDLK_q:
                case SDLK_d:
                    joueur.setPlayerState(state::idle);
                    break;
                }
                break;
            }
        }

        //mouvement du joueur
        joueur.addPlayerPose(WIDTH - 100);


        //remplissage du terrain
        SDL_SetRenderDrawColor(rendu.getRenderer(), 0, 0, 0, 255);
        rendu.cleanRenderer();

        //affichage de la balle
        SDL_SetRenderDrawColor(rendu.getRenderer(), 255, 255, 255, 255);
        SDL_RenderFillRect(rendu.getRenderer(), &joueur.rectPosPlayer());
        SDL_RenderFillRect(rendu.getRenderer(), &ballePlayer.getRectBalle());
        

        for (int l = 0; l < LIGNEBRIQUE; l++)
        {
            for (int c = 0; c < nbBrique; c++)
            {
                if (tabBric[l][c].getState() == true)
                {
                    SDL_RenderFillRect(rendu.getRenderer(), &tabBric[l][c].getRect());
                }
                
            }
            
        }
        

        rendu.afficheRenderer();
        // calculates to 60 fps
        SDL_Delay(1000 / 60);

    }

    rendu.afficheFin(&game, WIDTH, HEIGHT);
    if (!close)
    {
        SDL_Delay(5000);
    }
    

    rendu.destroyRenderer();
    rendu.destroyWindow();
    return 0;
}

//on va calcuer x source et y source est egale au numero de la taille modulo largeur du tileset par le tile size 
//y source est egale a numero de la taille divisé par hauteur du tileset fois tile size