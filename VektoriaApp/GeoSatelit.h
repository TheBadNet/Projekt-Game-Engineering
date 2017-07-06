#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;
class CGeoSatelit :	public CGeoTriangleTable
{
	//Satellit um die Erde
private:
	int stelle = 0;
public:
	void MachDreiecke(int eins, int zwei, int drei);
	void SetVertex(float x, float y, float z);
	CVertex m_satvert[200];
	CGeoSatelit();
	~CGeoSatelit();
};

