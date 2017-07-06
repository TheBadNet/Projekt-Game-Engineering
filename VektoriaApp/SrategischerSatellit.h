#pragma once
#include "GeoSatelit.h"
#include "PlayerShuttle.h"
class CSrategischerSatellit :
	public CPlacement
	//Punkte Satellit
{
private:
	CGeoSatelit m_zsat;
	CMaterial m_zsatmatpassive;
	CMaterial m_zsatmatactive;
	bool m_zbistaktiv = true;
	float m_zwartet = 0.0f;
	int m_anzahlplayerschonimarray=0;
	CPlayerShuttle *allplayers[4];
public:
	void punkteschicken(float ftimedelta);
	void spieleradden(CPlayerShuttle * player);
	void spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2);
	void spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3);
	void spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3, CPlayerShuttle * player4);
	CSrategischerSatellit(CHVector pos);
	~CSrategischerSatellit();
};