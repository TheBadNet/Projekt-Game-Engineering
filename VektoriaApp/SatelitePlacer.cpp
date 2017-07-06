#include "SatelitePlacer.h"



SatelitePlacer::SatelitePlacer(int count, CPlayerShuttle * player , CScene * myscene)
{
	srand(time(NULL));
	ActiveStalites = new CSrategischerSatellit*[count];
	Satelitecount = count;

	for (int i = 0; i < count; i++) 
	{
		ActiveStalites[i] = new CSrategischerSatellit(CHVector(rand() % 2500, rand() % 2000, rand() % 2250));
		myscene->AddPlacement(ActiveStalites[i]);
		ActiveStalites[i]->spieleradden(player);
	}
}
SatelitePlacer::SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CScene * myscene)
{
	srand(time(NULL));
	ActiveStalites = new CSrategischerSatellit*[count];
	Satelitecount = count;

	for (int i = 0; i < count; i++)
	{
		ActiveStalites[i] = new CSrategischerSatellit(CHVector(rand() % 2500, rand() % 2000, rand() % 2250));
		myscene->AddPlacement(ActiveStalites[i]);
		ActiveStalites[i]->spieleradden(player1, player2);
	}
}
SatelitePlacer::SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3, CScene * myscene)
{
	srand(time(NULL));
	ActiveStalites = new CSrategischerSatellit*[count];
	Satelitecount = count;

	for (int i = 0; i < count; i++)
	{
		ActiveStalites[i] = new CSrategischerSatellit(CHVector(rand() % 2500, rand() % 2000, rand() % 2250));
		myscene->AddPlacement(ActiveStalites[i]);
		ActiveStalites[i]->spieleradden(player1,player2,player3);
	}
}
SatelitePlacer::SatelitePlacer(int count, CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3, CPlayerShuttle * player4, CScene * myscene)
{

	srand(time(NULL));
	ActiveStalites = new CSrategischerSatellit*[count];
	Satelitecount = count;

	for (int i = 0; i < count; i++)
	{
		ActiveStalites[i] = new CSrategischerSatellit(CHVector(rand() % 2500, rand() % 2000, rand() % 2250));
		myscene->AddPlacement(ActiveStalites[i]);
		ActiveStalites[i]->spieleradden(player1, player2, player3, player4);
	}
}

void SatelitePlacer::CheckPlayers(float ftimedelta)
{
	for (int i = 0; i < Satelitecount; i++)
	{
		ActiveStalites[i]->punkteschicken(ftimedelta);
	}
}


SatelitePlacer::~SatelitePlacer()
{
	delete ActiveStalites;
}
