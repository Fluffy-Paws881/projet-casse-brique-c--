#pragma once
/*#define NBBRIQUE WIDTH / WBRIQUE - 2
#define WIDTH 800
#define WBRIQUE 40
#define LIGNEBRIQUE 5*/


class score
{
	int nbBrique;
	int life;
	int nbPoint;
	

public:

	score(int nbVie);

	//accesseur
	int getnbBric();
	int getnbLife();
	int getnbPoint();

	//mutateur 
	void addBrique();
	void addPoint();
	void substrLife();
	void substrBric();

	bool verifVictoire();



};
