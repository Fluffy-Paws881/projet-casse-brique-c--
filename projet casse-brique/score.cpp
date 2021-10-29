#include "score.h"

score::score(int nbVie)
{
	life = nbVie;
	nbBrique = 0;
	nbPoint = 0;
}

int score::getnbBric()
{
	return nbBrique;
}

int score::getnbLife()
{
	return life;
}

int score::getnbPoint()
{
	return nbPoint;
}

void score::addBrique()
{
	nbBrique += 1;
}

void score::addPoint()
{
	nbPoint += 1;
}

void score::substrLife()
{
	life -= 1;
}

void score::substrBric()
{
	nbBrique -= 1;
}

bool score::verifVictoire()
{
	if (nbBrique <= 0)
	{
		return true;
	}
	else {
		return false;
	}
	
}
