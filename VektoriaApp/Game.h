#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#pragma comment (lib, "ApiUtils_Debug64.lib")
#pragma comment (lib, "ApiNullRenderer_Debug64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug64.lib")
#pragma comment (lib, "ApiDirectInput08_Debug64.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug64.lib")
#pragma comment (lib, "ApiOpenGL40_Debug64.lib")
#pragma comment (lib, "ApiNullSound_Debug64.lib")
#pragma comment (lib, "ApiDirectSound_Debug64.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#pragma comment (lib, "ApiUtils_Release64.lib")
#pragma comment (lib, "ApiNullRenderer_Release64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release64.lib")
#pragma comment (lib, "ApiDirectInput08_Release64.lib")
#pragma comment (lib, "ApiDirectX11FP_Release64.lib")
#pragma comment (lib, "ApiOpenGL40_Release64.lib")
#pragma comment (lib, "ApiNullSound_Release64.lib")
#pragma comment (lib, "ApiDirectSound_Release64.lib")
#pragma comment (lib, "ApiRenderDistributed_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#pragma comment (lib, "ApiUtils_Debug.lib")
#pragma comment (lib, "ApiNullRenderer_Debug.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug.lib")
#pragma comment (lib, "ApiDirectInput08_Debug.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug.lib")
#pragma comment (lib, "ApiOpenGL40_Debug.lib")
#pragma comment (lib, "ApiNullSound_Debug.lib")
#pragma comment (lib, "ApiDirectSound_Debug.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#pragma comment (lib, "ApiUtils_Release.lib")
#pragma comment (lib, "ApiNullRenderer_Release.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release.lib")
#pragma comment (lib, "ApiDirectInput08_Release.lib")
#pragma comment (lib, "ApiDirectX11FP_Release.lib")
#pragma comment (lib, "ApiOpenGL40_Release.lib")
#pragma comment (lib, "ApiNullSound_Release.lib")
#pragma comment (lib, "ApiDirectSound_Release.lib")
#pragma comment (lib, "ApiRenderDistributed_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"
#include "GeoPointStar.h"
#include "Sternenbild.h"
#include "GeoSatelit.h"
#include "GeoRocket.h"
#include "Weaponlasercube.h"
#include "Planet.h"
#include "PlayerShuttle.h"
#include "SatelitePlacer.h"

using namespace Vektoria;


class CGame
{
public:
	CGame(void);																				// Wird vor Begin einmal aufgerufen (Konstruktor)
	~CGame(void);																				// Wird nach Ende einmal aufgerufen (Destruktor)

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	// Wird zu Begin einmal aufgerufen
	void Tick(float fTime, float fTimeDelta);													// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen
	void Fini();																				// Wird am Ende einmal aufgerufen
	void WindowReSize(int iNewWidth, int iNewHeight);											// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

	// Gamepad Steuerung
	void Bewegung();
	void Drehung();
private:
	//float m_zfps = 0.0f;
	// Standart
	CRoot m_zr;
	CScene m_zs;
	CFrame m_zf;
	CViewport m_zv;
	CCamera m_zc;
	CViewport m_zvplayzwei;
	// Placements
	CPlacement m_zpCam;
	CPlacement m_zpSonne;
	CPlacement m_zpLicht;
	CPlacement m_zpErdrot;
	CPlacement m_zpsat;

	// Objekte
	CLightRadial m_zLight;
	CGeoSphere m_zSonne;
	CBackground m_zBackground;
	CGeoSatelit m_zSat;

	// Images
	CImage m_ziSterne;

	// Materials
	CMaterial m_zmSonne;

	// Planeten
	// Erde
	CGeoSphere m_zErde;
	CPlacement m_zpErde;
	CMaterial m_zmErde;

	// Merkur
	CPlanet * m_pMerkur;
	/*CGeoSphere m_zMerkur;
	CPlacement m_zpMerkur;
	CMaterial m_zmMerkur;*/

	// Venus
	CPlanet * m_pVenus;
	//CGeoSphere m_zVenus;
	//CPlacement m_zpVenus;
	//CMaterial m_zmVenus;

	// Mars
	CPlanet * m_pMars;
	//CGeoSphere m_zMars;
	//CPlacement m_zpMars;
	//CMaterial m_zmMars;

	// Jupiter
	CPlanet * m_pJupiter;
	//CGeoSphere m_zJupiter;
	//CPlacement m_zpJupiter;
	//CMaterial m_zmJupiter;

	// Saturn
	CPlanet * m_pSaturn;
	//CGeoSphere m_zSaturn;
	//CPlacement m_zpSaturn;
	//CMaterial m_zmSaturn;

	// Uranus
	CPlanet * m_pUranus;
	//CGeoSphere m_zUranus;
	//CPlacement m_zpUranus;
	//CMaterial m_zmUranus;

	// Neptun
	CPlanet * m_pNeptun;
	//CGeoSphere m_zNeptun;
	//CPlacement m_zpNeptun;
	//CMaterial m_zmNeptun;

	// Monde
	CGeoSphere m_zErdmond;
	CPlacement m_zpErdmond;
	CMaterial m_zmErdmond;

	//Todesstern
	CGeoSphere m_zTodesstern;
	CPlacement m_zpTodesstern;
	CMaterial m_zmTodesstern;
	CGeoSphere m_zTodesAura;
	CMaterial m_zmTodesAura;

	// Ambient Light
	CLight m_zambient;
	CPlacement m_zpambient;

	//Bewegung
	bool m_AuraOn = false;
	float m_float = 1;

	// Eingabegeräte
	CDeviceKeyboard m_zdk;
	CDeviceGameController m_zdc;
	CDeviceCursor m_zdcur;

	// Geolist zum abfangen ob Objekt beim Klicken betroffen
	CGeos m_zgs;

	// Translations
	int m_zxbew = 0;
	int m_zybew = 0;
	int m_zxrot = 0;
	int m_zyrot = 0;
	int m_zhoehe = 0;

	// Background Sterne
	CGeoPointStar *m_zgPointStar = new CGeoPointStar();
	CMaterial m_zmsterne;

	// Easter Egg
	bool sternbild = false;
	CSternenbild *m_zSternenbild = new CSternenbild();

	// Zoom merke Sensitivity
	float m_zfsens = 0;

	// Raumschiff player2
	CPlayerShuttle playerone;
	CPlacement m_zpschiffcam;
	CCamera m_zcschiff;
	bool m_zbschiff = true;

	// Raumschiff player1
	CPlayerShuttle playertwo;
	CPlacement m_zpschiffcampl2;
	CCamera m_zcschiffpl2;
	bool m_zbschiffpl2 = true;


	// Skycube
	CGeoCube m_zskycube;
	CMaterial m_zmskycube;
	CPlacement m_zpskycube;

	// Spotlight für Erde
	CLightSpot m_zlerdespot;
	CPlacement m_zperdespot;
	CHVector m_zearthdir;


	// Waffensysteme player1
	CWeaponlasercube * Weapon;
	CWeaponlasercube * Weapon2;

	// SatelitePlacer
	SatelitePlacer * placer;
	
	// Soundtrack
	CAudio Soundtrack;

	void StatusChecker();
};