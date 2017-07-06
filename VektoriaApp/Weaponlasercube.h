#pragma once
#include "Vektoria\Root.h"
#include "WeaponProjectile.h"
using namespace Vektoria;
class CWeaponlasercube
	//Projektil manager
{
private:
	
	// std::vector<CWeaponProjectile> ActiveProjectiles;
	 //std::vector<CWeaponProjectile>::iterator itor;
	CWeaponProjectile *m_activeprojectiles[30];
	int m_count=0;
	CMaterial m_zmProjectile;
	CAudio laser;

public:

	CWeaponlasercube(CPlayerShuttle * player);
	void Shoot(CHVector Richtung, CPlayerShuttle * Caller, CScene * Scene, CPlayerShuttle *enemy);
	void Update(float ftimeDelta);
	~CWeaponlasercube();
};

