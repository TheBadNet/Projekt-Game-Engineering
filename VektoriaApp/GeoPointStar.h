#pragma once
#include "Vektoria\Root.h"


using namespace Vektoria;
// Sterne im Hintergrund
class CGeoPointStar : public CGeoPointList{
private:
	
	
public:
	//CGeoPointList m_zgPoints;
	CVertex m_astars[6000];
	CGeoPointStar();
	~CGeoPointStar(void);
};

