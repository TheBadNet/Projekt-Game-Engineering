#include "GeoRocket.h"



CGeoRocket::CGeoRocket()
{
	m_aav[0][0] = CHVector(0,0,0,1);
	m_aav[1][0] = CHVector(2, -5, 0, 1);
	m_aav[2][0] = CHVector(2.5, -10, 0, 1);
	m_aav[3][0] = CHVector(5, -12, 0, 1);

	m_aav[0][1] = CHVector(0, 0, 0, 1);
	m_aav[1][1] = CHVector(1.732, -5, 1, 1);
	m_aav[2][1] = CHVector(2.165, -10, 1.25, 1);
	m_aav[3][1] = CHVector(4.330, -12, 2.5, 1);

	m_aav[0][2] = CHVector(0, 0, 0, 1);
	m_aav[1][2] = CHVector(1, -5, 1.732, 1);
	m_aav[2][2] = CHVector(1.25, -10, 2.165, 1);
	m_aav[3][2] = CHVector(2.5, -12, 4.330, 1);

	m_aav[0][3] = CHVector(0, 0, 0, 1);
	m_aav[1][3] = CHVector(0, -5, 2, 1);
	m_aav[2][3] = CHVector(0, -10, 2.5, 1);
	m_aav[3][3] = CHVector(0, -12, 5, 1);

	this->AddPatch(m_aav, 20, 20);

	
	for(int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				CHMat m;
				m.RotateY(HALFPI);
				m_aav[i][j] = m * m_aav[i][j];
			}

		this->AddPatch(m_aav, 20, 20);

		
	}


		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				CHMat m;
//				CHMat t;
				m.RotateX(PI);
				m.TranslateYDelta(-24);
				m_aav[i][j] = m * m_aav[i][j];
			}

		this->AddPatch(m_aav, 20, 20);

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				CHMat m;
				m.RotateY(HALFPI);
				m_aav[i][j] = m * m_aav[i][j];
			}
		this->AddPatch(m_aav, 20, 20);
	}

	this->AddPatch(m_aav, 20, 20);

	Init();

	CMaterial * pzm = new CMaterial();
//	pzm->LoadPreset("MetalRustyFlaking");
	pzm->MakeTextureDiffuse("textures\\schiff.jpg");
	SetMaterial(pzm);
}													  


CGeoRocket::~CGeoRocket()
{
}
