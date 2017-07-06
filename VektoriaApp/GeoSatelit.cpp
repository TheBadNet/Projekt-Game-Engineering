#include "GeoSatelit.h"



CGeoSatelit::CGeoSatelit()
{
	//Oben Deckel 0-7
	SetVertex(2.5, 10, 5);
	SetVertex(5, 10, 2.5);
	SetVertex(5, 10, -2.5);
	SetVertex(2.5, 10, -5);
	SetVertex(-2.5, 10, -5);
	SetVertex(-5, 10, -2.5);
	SetVertex(-5, 10, 2.5);
	SetVertex(-2.5, 10, 5);

	//Mitte 8-15
	SetVertex(2.5, 0, 5);
	SetVertex(5, 0, 2.5);
	SetVertex(5, 0, -2.5);
	SetVertex(2.5, 0, -5);
	SetVertex(-2.5, 0, -5);
	SetVertex(-5, 0, -2.5);
	SetVertex(-5, 0, 2.5);
	SetVertex(-2.5, 0, 5);

	//Unten Deckel 16-23
	SetVertex(2.5, -10, 5);
	SetVertex(5, -10, 2.5);
	SetVertex(5, -10, -2.5);
	SetVertex(2.5, -10, -5);
	SetVertex(-2.5, -10, -5);
	SetVertex(-5, -10, -2.5);
	SetVertex(-5, -10, 2.5);
	SetVertex(-2.5, -10, 5);

	//Rechtes Panel 24-29
	SetVertex(10, 0, 2.5);
	SetVertex(10, 0, -2.5);
	SetVertex(10, 0, 7.5);
	SetVertex(10, 0, -7.5);
	SetVertex(30, 0, 7.5);
	SetVertex(30, 0, -7.5);
	
	//Linkes Panel 30-35
	SetVertex(-10, 0, 2.5);
	SetVertex(-10, 0, -2.5);
	SetVertex(-10, 0, 7.5);
	SetVertex(-10, 0, -7.5);
	SetVertex(-30, 0, 7.5);
	SetVertex(-30, 0, -7.5);

	//Mittelpunkte
	//36
	SetVertex(0, 10, 0);
	//37
	SetVertex(0, -10, 0);


	for (int i = 0; i < stelle; i++) {
		this->AddVertex(&m_satvert[i]);
	}

	//Index Immer 3 = ein Dreieck
	//Oben Deckel
	MachDreiecke(7, 36, 6);
	MachDreiecke(6, 36, 5);
	MachDreiecke(5, 36, 4);
	MachDreiecke(4, 36, 3);
	MachDreiecke(3, 36, 2);
	MachDreiecke(2, 36, 1);
	MachDreiecke(1, 36, 0);
	MachDreiecke(0, 36, 7);
	//Mitte
	MachDreiecke(0, 15, 8);
	MachDreiecke(0, 8, 1);
	MachDreiecke(1, 8, 9);
	MachDreiecke(1, 9, 2);
	MachDreiecke(2, 9, 10);
	MachDreiecke(2, 10, 3);
	MachDreiecke(3, 10, 11);
	MachDreiecke(3, 11, 4);
	MachDreiecke(4, 11, 12);
	MachDreiecke(4, 12, 5);
	MachDreiecke(5, 12, 13);
	MachDreiecke(5, 13, 6);
	MachDreiecke(6, 13, 14);
	MachDreiecke(6, 14, 7);
	MachDreiecke(7, 14, 15);
	MachDreiecke(7, 15, 0);
	//Unten
	MachDreiecke(8, 23, 16);
	MachDreiecke(8, 16, 17);
	MachDreiecke(9, 8, 17);
	MachDreiecke(9, 17, 18);
	MachDreiecke(10, 9, 18);
	MachDreiecke(10, 18, 19);
	MachDreiecke(11, 10, 19);
	MachDreiecke(11, 19, 20);
	MachDreiecke(12, 11, 20);
	MachDreiecke(12, 20, 21);
	MachDreiecke(13, 12, 21);
	MachDreiecke(13, 21, 22);
	MachDreiecke(14, 13, 22);
	MachDreiecke(14, 22, 23);
	MachDreiecke(15, 14, 23);
	MachDreiecke(15, 23, 8);
	//Unten Deckel
	MachDreiecke(16, 37, 17);
	MachDreiecke(17, 37, 18);
	MachDreiecke(18, 37, 19);
	MachDreiecke(19, 37, 20);
	MachDreiecke(20, 37, 21);
	MachDreiecke(21, 37, 22);
	MachDreiecke(22, 37, 23);
	MachDreiecke(23, 37, 16);
	//Rechte Seite Wing
	MachDreiecke(13, 14, 25);
	MachDreiecke(14, 24, 25);
	MachDreiecke(25, 29, 27);
	MachDreiecke(24, 29, 25);
	MachDreiecke(24, 28, 29);
	MachDreiecke(24, 26, 28);
	MachDreiecke(13, 25, 14);
	MachDreiecke(14, 25, 24);
	MachDreiecke(25, 27, 29);
	MachDreiecke(24, 25, 29);
	MachDreiecke(24, 29, 28);
	MachDreiecke(24, 28, 26);
	//Linke Seite Wing
	MachDreiecke(10, 31, 9);
	MachDreiecke(9, 31, 30);
	MachDreiecke(31, 33, 35);
	MachDreiecke(30, 31, 35);
	MachDreiecke(30, 35, 34);
	MachDreiecke(30, 34, 32);
	MachDreiecke(10, 9, 31);
	MachDreiecke(9, 30, 31);
	MachDreiecke(31, 35, 33);
	MachDreiecke(30, 35, 31);
	MachDreiecke(30, 34, 35);
	MachDreiecke(30, 32, 34);



}


CGeoSatelit::~CGeoSatelit()
{
}


void CGeoSatelit::SetVertex(float x, float y, float z) {
	float zz = 0, fx = x, fy = y, fz = z;
	CHVector vPos = CHVector(fx, fy, fz, 1.0f);
	CHVector vNormal = vPos;
	vNormal.SetW(0.0f);
	vNormal.Normal();
	if (fy != 0) {
		zz = ((-fz) / fy);
	}
	CHVector vTangent = CHVector(0.0f, zz, 1.0f, 0.0f);//zz an 2. Stelle , 1.0f an 3. Stelle
	float fu = 1.0f, fv = 0.0f;
	m_satvert[stelle].Init(vPos, vNormal, vTangent, fu, fv);
	this->AddVertex(&m_satvert[stelle]);
	stelle++;
}

void CGeoSatelit::MachDreiecke(int eins, int zwei, int drei) {
	this->AddIndex(eins);
	this->AddIndex(zwei);
	this->AddIndex(drei);
}