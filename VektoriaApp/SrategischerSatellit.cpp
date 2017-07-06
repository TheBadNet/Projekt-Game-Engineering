#include "SrategischerSatellit.h"



void CSrategischerSatellit::punkteschicken(float ftimedelta) // in Tick aufrufen
{
	if (m_zbistaktiv) {
		for (int i = 0; i < m_anzahlplayerschonimarray; i++) {
			if (allplayers[i]->GetPos().Dist(this->GetPos()) < 20 && allplayers[i]->GetPos().Dist(this->GetPos()) > -20) {
				allplayers[i]->changepoints(20);
				m_zbistaktiv = false;
				m_zsat.SetMaterial(&m_zsatmatactive);
				// TODO: Textur ändern hier auf rot oder so
			}
		}
	}
	else if (m_zwartet > 60.00f) {
		m_zbistaktiv = true;
		m_zwartet = 0.0f;
		m_zsat.SetMaterial(&m_zsatmatpassive);
		// TODO: Textur wieder zurück ändern
	}
	else {
		m_zwartet += ftimedelta;
	}
}

void CSrategischerSatellit::spieleradden(CPlayerShuttle * player) 
{
	allplayers[0] = player;
	m_anzahlplayerschonimarray = 1;
}

void CSrategischerSatellit::spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2)
{
	allplayers[0] = player1;
	allplayers[1] = player2;
	m_anzahlplayerschonimarray = 2;
}
void CSrategischerSatellit::spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3)
{
	allplayers[0] = player1;
	allplayers[1] = player2;
	allplayers[2] = player3;
	m_anzahlplayerschonimarray = 3;
}
void CSrategischerSatellit::spieleradden(CPlayerShuttle * player1, CPlayerShuttle * player2, CPlayerShuttle * player3, CPlayerShuttle * player4)
{
	allplayers[0] = player1;
	allplayers[1] = player2;
	allplayers[2] = player3;
	allplayers[3] = player4;
	m_anzahlplayerschonimarray = 4;
}

CSrategischerSatellit::CSrategischerSatellit(CHVector pos)
{
	this->AddGeo(&m_zsat);
	this->ScaleDelta(0.1f);
	this->Translate(pos);
	m_zsatmatpassive.MakeTextureDiffuse("textures\\green_image.jpg");
	m_zsatmatactive.MakeTextureDiffuse("textures\\red_image.jpg");
	m_zsat.SetMaterial(&m_zsatmatpassive);
}


CSrategischerSatellit::~CSrategischerSatellit()
{
}
