#include "Planet.h"



CPlanet::CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed)
{
	m_pmaterial.MakeTextureDiffuse(matdir);
	m_pgeometry.Init(size, &m_pmaterial, iLongitude, iLatitude);
	this->AddGeo(&m_pgeometry);
	this->Translate(pos);
	this->pos = pos;
	this->revspeed = revspeed;
}

CPlanet::CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed, char additionaldir[255], bool isglow)
{
	m_pmaterial.MakeTextureDiffuse(matdir);
	if(isglow)
		m_pmaterial.MakeTextureGlow(additionaldir);
	else
		m_pmaterial.MakeTextureBump(additionaldir);
	m_pgeometry.Init(size, &m_pmaterial, iLongitude, iLatitude);
	this->AddGeo(&m_pgeometry);
	this->Translate(pos);
	this->pos = pos;
	this->revspeed = revspeed;
}


CPlanet::CPlanet(float size, int iLongitude, int iLatitude, char matdir[255], CHVector pos, float revspeed, char glowdir[255], char bumpdir[255])
{
	m_pmaterial.MakeTextureDiffuse(matdir);
	m_pmaterial.MakeTextureBump(bumpdir);
	m_pmaterial.MakeTextureGlow(glowdir);
	m_pgeometry.Init(size, &m_pmaterial, iLongitude, iLatitude);
	this->AddGeo(&m_pgeometry);
	this->Translate(pos);
	this->pos = pos;
	this->revspeed = revspeed;
}


void CPlanet::SetTextureDiff(char matdir[255])
{
	m_pmaterial.MakeTextureDiffuse(matdir);
}
void CPlanet::SetTextureBump(char bumpdir[255])
{
	m_pmaterial.MakeTextureBump(bumpdir);
}
void CPlanet::SetTextureGlow(char glowdir[255])
{
	m_pmaterial.MakeTextureGlow(glowdir);
}

void CPlanet::revolution(float fTime)
{
	this->RotateYDelta(revspeed*fTime);
	this->pos = this->GetPos();
	this->TranslateDelta(-pos);
	this->RotateYDelta(fTime);
	this->TranslateDelta(pos);
}

CPlanet::~CPlanet()
{
	delete &m_pmaterial;
	delete &m_pgeometry;
	delete this;
}
