#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

// Raumschiff für Spieler

class CGeoRocket : public CGeoBezierTable
{
public:
	CHVector m_aav[4][4];
	CGeoRocket();
	~CGeoRocket();
};

