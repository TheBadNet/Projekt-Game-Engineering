#include "PlayerShuttle.h"



void CPlayerShuttle::changepoints(int points)
{
	// Punkte aufaddieren oder abziehen
	this->points += points;

	// Punktebereich zwischen 0 und 100
	if (this->points > 100)
		this->points = 100;
	else if (this->points < 0)
		this->points = 0;
}

void CPlayerShuttle::uebergibvieport(CViewport *m_zv)
{
	this->m_zv = m_zv;
	m_zfFont.LoadPreset("PrestigeEliteWhite");
	m_zfFont.SetChromaKeyingOn();
	m_zwPkte.Init(CFloatRect(0, 0, 0.1, 0.05), 10, &m_zfFont);
	this->m_zv->AddWriting(&m_zwPkte);
	loose.InitFull("textures\\verloren.jpg");
	win.InitFull("textures\\gewonnen.jpg");
	this->m_zv->AddOverlay(&win);
	this->m_zv->AddOverlay(&loose);
	win.SwitchOff();
	loose.SwitchOff();
}

void CPlayerShuttle::triggerverloren()
{
	loose.SwitchOn();
}

void CPlayerShuttle::triggergewonnen()
{
	win.SwitchOn();
}

void CPlayerShuttle::zeigepunktean()
{
	m_zwPkte.PrintInt(points);
}

void CPlayerShuttle::playexplosion()
{
	explosion.Start();
}

bool CPlayerShuttle::checkpoints()
{
	if (points == 0)
		return true;
	else 
		return false;
}


CPlayerShuttle::CPlayerShuttle()
{
	m_zrocket.Init();
	m_zrocket.Flip();
	this->AddPlacement(&m_zpausrichtung);
	m_zpausrichtung.AddGeo(&m_zrocket);
	m_zpausrichtung.RotateXDelta(-HALFPI);
	m_zpausrichtung.TranslateZDelta(-6);
	explosion.Init3D("sound\\explosion.wav", 50.0f);
	this->AddAudio(&explosion);
}

CPlayerShuttle::~CPlayerShuttle()
{
}