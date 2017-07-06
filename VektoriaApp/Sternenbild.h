#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

//Sterne plazieren
class CSternenbild : public CGeoLineList
{
private:
	int stelle = 0;
	CMaterial mymat;
public:
	CVertex m_schrift[200];
	void SetVertex(float x, float y, float z);
	CSternenbild();
	~CSternenbild();
};

