#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

// Raumschiff f�r Spieler

class CGeoRocket : public CGeoBezierTable
{
public:
	CHVector m_aav[4][4];
	CGeoRocket();
	~CGeoRocket();
};

