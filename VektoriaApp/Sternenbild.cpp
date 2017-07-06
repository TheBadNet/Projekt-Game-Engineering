#include "Sternenbild.h"



CSternenbild::CSternenbild()
{
	//1
	SetVertex(-4000, 1000, -16000);
	//2
	SetVertex(-4000, 2000, -16000);
	SetVertex(-4000, 2000, -16000);
	//3
	SetVertex(-3400, 1800, -16000);
	SetVertex(-3400, 1800, -16000);
	//4
	SetVertex(-3400, 1200, -16000);
	SetVertex(-3400, 1200, -16000);
	//5
	SetVertex(-4000, 1000, -16000);
	//D

	//6
	SetVertex(-3200, 1000, -16000);
	//7
	SetVertex(-3050, 1500, -16000);
	SetVertex(-3050, 1500, -16000);
	//8
	SetVertex(-2900, 2000, -16000);
	SetVertex(-2900, 2000, -16000);
	//9
	SetVertex(-2750, 1500, -16000);
	SetVertex(-2750, 1500, -16000);
	//10
	SetVertex(-2600, 1000, -16000);
	SetVertex(-3050, 1500, -16000);
	SetVertex(-2750, 1500, -16000);

	//A

	SetVertex(-2400, 1000, -16000);
	SetVertex(-2200, 2000, -16000);
	SetVertex(-2200, 2000, -16000);
	SetVertex(-2000, 1000, -16000);
	SetVertex(-2000, 1000, -16000);
	SetVertex(-1800, 2000, -16000);
	//N

	SetVertex(-1600, 1000, -16000);
	SetVertex(-1600, 2000, -16000);
	SetVertex(-1600, 1500, -16000);
	SetVertex(-1000, 2000, -16000);
	SetVertex(-1600, 1500, -16000);
	SetVertex(-1000, 1000, -16000);
	//K

	SetVertex(-200, 1000, -16000);
	SetVertex(-50, 2000, -16000);
	SetVertex(-50, 2000, -16000);
	SetVertex(100, 1000, -16000);
	SetVertex(100, 1000, -16000);
	SetVertex(250, 2000, -16000);
	SetVertex(250, 2000, -16000);
	SetVertex(400, 1000, -16000);
	//M

	SetVertex(600, 1000, -16000);
	SetVertex(1200, 1000, -16000);
	SetVertex(600, 1000, -16000);
	SetVertex(600, 2000, -16000);
	SetVertex(600, 2000, -16000);
	SetVertex(1200, 2000, -16000);
	SetVertex(600, 1500, -16000);
	SetVertex(1000, 1500, -16000);
	//E

	SetVertex(1400, 1000, -16000);
	SetVertex(1550, 2000, -16000);
	SetVertex(1550, 2000, -16000);
	SetVertex(1700, 1000, -16000);
	SetVertex(1700, 1000, -16000);
	SetVertex(1850, 2000, -16000);
	SetVertex(1850, 2000, -16000);
	SetVertex(2000, 1000, -16000);
	//M

	SetVertex(2200, 1000, -16000);
	SetVertex(2800, 1000, -16000);
	SetVertex(2200, 1000, -16000);
	SetVertex(2200, 2000, -16000);
	SetVertex(2200, 2000, -16000);
	SetVertex(2800, 2000, -16000);
	SetVertex(2200, 1500, -16000);
	SetVertex(2800, 1500, -16000);
	//E

	SetVertex(3000, 1000, -16000);
	SetVertex(3600, 1000, -16000);
	SetVertex(3600, 1000, -16000);
	SetVertex(3600, 1500, -16000);
	SetVertex(3600, 1500, -16000);
	SetVertex(3000, 1500, -16000);
	SetVertex(3000, 1500, -16000);
	SetVertex(3000, 2000, -16000);
	SetVertex(3000, 2000, -16000);
	SetVertex(3600, 2000, -16000);


	this->Init();
	mymat.MakeTextureDiffuse("textures\\yellow.png");
	this->SetMaterial(&mymat);
}


CSternenbild::~CSternenbild()
{
}

void CSternenbild::SetVertex(float x, float y, float z) {
	float zz = 0, fx = x, fy = y, fz = z;

	CHVector vPos = CHVector(fx, fy, fz, 1.0f);
	CHVector vNormal = vPos;
	vNormal.SetW(0.0f);
	vNormal.Normal();
	if (fy != 0) {
		zz = ((-fz) / fy);
	}
	CHVector vTangent = CHVector(0.0f, zz, 1.0f, 0.0f);
	float fu = 1.0f, fv = 0.0f;
	m_schrift[stelle].Init(vPos, vNormal, vTangent, fu, fv);
	this->AddVertex(&m_schrift[stelle]);
	stelle++;
}