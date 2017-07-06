#pragma once
#include "SrategischerSatellit.h"
#include "time.h"
//Plaziert/managed Satelliten
class SatelitePlacer
{
private:

	CSrategischerSatellit ** ActiveStalites;
	int Satelitecount;

public:
	SatelitePlacer(int count, CPlayerShuttle * player, CScene * myscene);
	SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CScene * myscene);
	SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3, CScene * myscene);
	SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3,CPlayerShuttle * player4 , CScene * myscene);
	void CheckPlayers(float ftimedelta);
	~SatelitePlacer();
};

