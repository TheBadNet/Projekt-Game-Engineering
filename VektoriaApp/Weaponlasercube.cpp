#include "Weaponlasercube.h"



CWeaponlasercube::CWeaponlasercube(CPlayerShuttle * player)
{
	m_zmProjectile.MakeTextureDiffuse("textures\\Red.jpg");
	laser.Init3D("sound\\laser.wav", 50.0f);
	player->AddAudio(&laser);
}

void CWeaponlasercube::Shoot(CHVector Richtung, CPlayerShuttle * Caller, CScene * Scene, CPlayerShuttle *enemy)
{
	if (m_count <30) {
		m_activeprojectiles[m_count] = new CWeaponProjectile(Richtung, Caller, Scene, &m_zmProjectile, enemy);

		static bool bStarted = false;
		laser.Start();
		m_count++;
	}
	//ActiveProjectiles.emplace_back(Richtung, Caller, Scene);
}

void CWeaponlasercube::Update(float ftimeDelta)
{
	if (m_count != 0) {
		for (int i=0; i<m_count; i++)
		{
			if (m_activeprojectiles[i]->Doit(ftimeDelta) >= 5)
			{
				delete m_activeprojectiles[i];
				m_count--;
				for (int j = i; j < m_count; j++) 
				{
					m_activeprojectiles[j] = m_activeprojectiles[j+1];
				}
					
			}
			//break;
		}
	}
}

CWeaponlasercube::~CWeaponlasercube()
{

}
