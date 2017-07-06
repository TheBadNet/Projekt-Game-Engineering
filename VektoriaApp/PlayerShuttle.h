#pragma once
#include "Vektoria\Root.h"
#include "GeoRocket.h"

using namespace Vektoria;
//Spieler
class CPlayerShuttle :
	public CPlacement
{
private:
	int points = 50;
	CGeoRocket m_zrocket;
	CPlacement m_zpausrichtung;
	CViewport *m_zv;
	CWritingFont m_zfFont;
	CWriting m_zwPkte;
	COverlay win;
	COverlay loose;
	CAudio explosion;

public:
	void changepoints(int points);
	void uebergibvieport(CViewport *m_zv);
	void triggerverloren();
	void triggergewonnen();
	bool checkpoints();
	void zeigepunktean();
	void playexplosion();
	CPlayerShuttle();
	~CPlayerShuttle();
};

