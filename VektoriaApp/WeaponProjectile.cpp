#include "WeaponProjectile.h"



CWeaponProjectile::CWeaponProjectile(CHVector Richtung, CPlayerShuttle * Caller, CScene * Scene, CMaterial * m_zmProjectile, CPlayerShuttle * enemy)
{
	m_zcuProjectile.Init(0.5f, m_zmProjectile);
	this->Translate(Caller->GetPos());
	this->AddGeo(&m_zcuProjectile);
	this->Richtung = Richtung;
	Scene->AddPlacement(this);
	m_thisscene = Scene;
	this->enemy = enemy;
}



float CWeaponProjectile::Doit(float ftimeDelta)
{
	this->TranslateDelta(Richtung * ftimeDelta * 200);
	timeTravled += ftimeDelta;

	// Hit und 10 Punkte Anzug
	if (enemy->GetPos().Dist(this->GetPos()) < 20 && enemy->GetPos().Dist(this->GetPos()) > -20)
 	{
		enemy->changepoints(-10);
		enemy->playexplosion();
		return 5.5f;
	}
	return timeTravled;
}

CWeaponProjectile::~CWeaponProjectile()
{
 	m_thisscene->SubPlacement(this);
}

bool CWeaponProjectile::hitdetection()
{
	if (enemy->GetPos().Dist(this->GetPos()) < 10)
		return true;
	else
		return false;
}
