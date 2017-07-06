#pragma once

#include "Vektoria\Root.h"

using namespace Vektoria;
//Planeten
class CPlanet :
	public CPlacement
{

private:

	CGeoSphere m_pgeometry;
	CMaterial m_pmaterial;
	CHVector pos;
	float revspeed;

public:
	CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed);
	CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed, char additionaldir[255], bool isglow);
	CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed, char glowdir[255], char bumpdir[255]);
	void revolution(float fTime);
	void SetTextureDiff(char matdir[255]);
	void SetTextureBump(char bumpdir[255]);
	void SetTextureGlow(char glowdir[255]);
	~CPlanet();
};

