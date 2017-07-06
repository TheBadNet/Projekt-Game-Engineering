#include "GeoPointStar.h"


CGeoPointStar::CGeoPointStar()
{
	float z,fx,fy,fz;
	int xmult = 2;
	srand(time(NULL));
	for (int i = 0; i < 6000; i++){
		if (i < 2000) {
			if (rand() % 2) {
				fx = 8000* xmult;
			}
			else {
				fx = -8000* xmult;
			}
			fy = (rand() % 16000* xmult - 8000* xmult);
			fz = (rand() % 16000* xmult - 8000* xmult);
		}
		else if (i < 4000) {
			if (rand() % 2) {
				fy = 8000* xmult;
			}
			else {
				fy = -8000* xmult;
			}
			fx = (rand() % 16000* xmult - 8000* xmult);
			fz = (rand() % 16000* xmult - 8000* xmult);
		}
		else {
			if (rand() % 2) {
				fz = 8000* xmult;
			}
			else {
				fz = -8000* xmult;
			}
			fx = (rand() % 16000* xmult - 8000* xmult);
			fy = (rand() % 16000* xmult -8000* xmult);
		}
		CHVector vPos = CHVector(fx,fy,fz,1.0f);
		CHVector vNormal = -vPos;
		vNormal.SetW(0.0f);
		vNormal.Normal();
		if(fy!=0)
		z = ((-fz)/fy);
		CHVector vTangent = CHVector(0.0f, z, 1.0f, 0.0f);
		float fu = 1.0f;
		float fv = 0.0f;

		m_astars[i].Init(vPos, vNormal, vTangent, fu, fv);
		//m_zgPoints.AddVertex(&m_astars[i]);
		this->AddVertex(&m_astars[i]);
	}

	//m_zgPoints.Init();
	this->Init();
};


CGeoPointStar::~CGeoPointStar()
{
}
