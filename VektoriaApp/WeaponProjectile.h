#pragma once
#include "Vektoria\Root.h"
#include "PlayerShuttle.h"
using namespace Vektoria;
class CWeaponProjectile :
	public CPlacement
	//Laserprojektile
{
private:

	CGeoCube m_zcuProjectile;
	CHVector Richtung;
	float timeTravled = 0.0f;
	float abstand;
	CScene *m_thisscene;
	CPlayerShuttle * enemy;

public:
	CWeaponProjectile(CHVector Richtung, CPlayerShuttle * Caller, CScene * Scene, CMaterial * m_zmProjectile, CPlayerShuttle * enemy);
	float Doit(float ftimeDelta);
	bool hitdetection();
	~CWeaponProjectile();
};

