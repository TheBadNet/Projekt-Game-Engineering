#include "StdAfx.h"
#include "Game.h"



CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	// Cam, Frame, Viewport, Scene
	m_zr.Init(psplash);
	m_zc.Init(HALFPI);
	m_zf.Init(hwnd, procOS);
	//m_zv.InitFull(&m_zc);
	m_zv.InitHalfLeft(&m_zcschiff);
	m_zvplayzwei.InitHalfRight(&m_zcschiffpl2);
	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	m_zf.AddViewport(&m_zvplayzwei);
	m_zr.AddScene(&m_zs);
	// m_zv.SetBackfaceCullingOff();
	

	// Images
	m_ziSterne.Init("textures\\black_image.jpg");
	//m_ziSterne.Init("textures\\stars.jpg");
	m_zv.AddBackground(&m_zBackground);

	// Materials
	m_zmSonne.MakeTextureDiffuse("textures\\sonne.jpg");
	m_zmSonne.MakeTextureGlow("textures\\sonne.jpg");
	m_zmSonne.SetGlowStrength(3);
	// m_zmSonne.SetLightScatteringOn();
	m_zmSonne.SetTransparencyOn();
	

	//Sonne
	m_zLight.Init(CColor(1, 1, 1),1);
	m_zLight.SwitchOff();
	m_zSonne.Init(309.543937, &m_zmSonne, 200, 200);
	m_zBackground.InitFull(&m_ziSterne);
	
	// Placements
	m_zs.AddPlacement(&m_zpCam);
	m_zs.AddPlacement(&m_zpLicht);
	m_zs.AddPlacement(&m_zpSonne);
	m_zs.SetLightAmbient(CColor(1, 1, 1));
	m_zs.SetLightAmbient(0.5);
	
	// Add
	m_zpCam.AddCamera(&m_zc);
	m_zpSonne.AddGeo(&m_zSonne);
	m_zpLicht.AddLightRadial(&m_zLight);

	// Translations
	m_zpCam.RotateXDelta(-0.7854);
	m_zpCam.TranslateDelta(0, 1000, 1000);

	// Planeten

	//Todesstern
	m_zTodesstern.Init(15, &m_zmTodesstern, 200, 200);
	m_zpTodesstern.AddGeo(&m_zTodesstern);
	m_zmTodesstern.MakeTextureDiffuse("textures\\Todesstern.png");
	m_zpErde.AddPlacement(&m_zpTodesstern);
	m_zpTodesstern.TranslateXDelta(100);
	m_zTodesAura.Init(17, &m_zmTodesAura, 200, 200);
	m_zpTodesstern.AddGeo(&m_zTodesAura);
	m_zmTodesAura.MakeTextureDiffuse("textures\\Red.jpg");
	m_zmTodesAura.SetTransparency(1);
	m_zgs.Add(&m_zTodesstern);

	// Merkur
	m_pMerkur = new CPlanet(10.85425,200,200, "textures\\Merkur.jpg", CHVector(400, 0, 0), 0.415);
	m_zs.AddPlacement(m_pMerkur);

	// Venus
	m_pVenus = new CPlanet(26.92545,200,200, "textures\\Venus.jpg", CHVector(480, 0, 0), 0.16255);
	m_zs.AddPlacement(m_pVenus);

	// Erde
	m_zErde.Init(28.33145, &m_zmErde, 200, 200);
	m_zpErde.AddPlacement(&m_zpErdrot);
	m_zmErde.MakeTextureDiffuse("textures\\erde.jpg");
	m_zpSonne.AddPlacement(&m_zpErde);
	m_zpErde.AddPlacement(&m_zpErdmond);
	m_zpErdrot.AddGeo(&m_zErde);

	m_zpsat.ScaleDelta(0.1f);
	m_zpsat.TranslateYDelta(100);
	m_zpErde.AddPlacement(&m_zpsat);
	m_zpsat.AddGeo(&m_zSat);

	// Mars
	m_pMars = new CPlanet(26.92545, 200, 200, "textures\\Mars.jpg", CHVector(800, 0, 0), 0.0531683);
	m_zs.AddPlacement(m_pMars);

	// Jupiter
	m_pJupiter = new CPlanet(307.7775, 200, 200, "textures\\Jupiter.jpg", CHVector(1500, 0, 0), 0.00843);
	m_zs.AddPlacement(m_pJupiter);

	// Saturn
	m_pSaturn = new CPlanet(255.0211345, 200, 200, "textures\\Saturn.jpg", CHVector(2200, 0, 0), 0.003394);
	m_zs.AddPlacement(m_pSaturn);

	// Uranus
	m_pUranus = new CPlanet(112.4182, 200, 200, "textures\\Uranus.jpg", CHVector(3000, 0, 0), 0.0011902);
	m_zs.AddPlacement(m_pUranus);

	// Neptun
	m_pNeptun = new CPlanet(109.2435, 200, 200, "textures\\Neptun.jpg", CHVector(3800, 0, 0), 0.0006068);
	m_zs.AddPlacement(m_pNeptun);

	// Monde
	m_zErdmond.Init(10, &m_zmErdmond, 100, 100);
	m_zpErdmond.AddGeo(&m_zErdmond);
	m_zmErdmond.MakeTextureDiffuse("textures\\Erdmond.jpg");
	m_zpErde.AddPlacement(&m_zpErdmond);
	

	// Sensitivity
	m_zpCam.SetTranslationSensitivity(100);
	m_zpCam.SetRotationSensitivity(2);
	playerone.SetTranslationSensitivity(100);
	playerone.SetRotationSensitivity(1.5);

	// Devices an Frame anhängen
	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zf.AddDeviceGameController(&m_zdc);
	m_zf.AddDeviceCursor(&m_zdcur);


	// Test
	//m_zmsterne.MakeTextureDiffuse("textures\\Erdmond.jpg");

	// Test ende

	// Hintergrundsterne
	//m_zpSonne.AddGeo(m_zgPointStar);

	// Weiter Sehen 
	m_zc.SetFarClipping(50000.0f); //30000.0f
	
	// Versuch Placement PlayerOne 
	playerone.uebergibvieport(&m_zv);
	m_zs.AddPlacement(&playerone);
	playerone.AddPlacement(&m_zpschiffcam);
	m_zpschiffcam.AddCamera(&m_zcschiff);
	playerone.RotateXDelta(-HALFPI);
	playerone.TranslateXDelta(400);

	// Versuch Placement PlayerTwo
	playertwo.uebergibvieport(&m_zvplayzwei);
	m_zs.AddPlacement(&playertwo);
	playertwo.AddPlacement(&m_zpschiffcampl2);
	m_zpschiffcampl2.AddCamera(&m_zcschiffpl2);
	playertwo.RotateXDelta(-HALFPI);
	playertwo.TranslateXDelta(-400);
	

	// Rocket pl2 Startposition und Rotation und Cam

	m_zpschiffcampl2.RotateXDelta(-QUARTERPI*0.25);
	m_zpschiffcampl2.TranslateYDelta(25);
	m_zpschiffcampl2.TranslateZDelta(40);
	m_zcschiffpl2.SetFov(HALFPI, HALFPI / m_zc.m_fViewportAspectRatio);
	m_zcschiffpl2.Init(HALFPI);

	// Rocket Startposition und Rotation und Cam
	m_zpschiffcam.RotateXDelta(-QUARTERPI*0.25);
	m_zpschiffcam.TranslateYDelta(25);
	m_zpschiffcam.TranslateZDelta(40);
	m_zcschiff.SetFov(HALFPI, HALFPI / m_zc.m_fViewportAspectRatio);
	m_zcschiff.Init(HALFPI);

	// Skycube
	m_zmskycube.MakeTextureSky("textures\\skycube.jpg");
	m_zskycube.Init(17000,17000,17000,&m_zmskycube,1.0f,true);
	m_zpskycube.AddGeo(&m_zskycube);
	//m_zpskycube.SetSky();
	m_zpskycube.AddGeo(m_zgPointStar);
	m_zs.AddPlacement(&m_zpskycube);

	// Spotlight für Erde
	m_zs.AddPlacement(&m_zperdespot);
	m_zperdespot.AddLightSpot(&m_zlerdespot);
	m_zlerdespot.SetAngles(0.08, 0.10);
	m_zlerdespot.SetMinDistance(250);
	m_zlerdespot.SetMaxDistance(300);
	m_zlerdespot.SetShadowOn();
	m_zlerdespot.SetShadowMapResolution(512,512);

	//Sateliten Plazieren
	placer = new SatelitePlacer(20, &playerone, &playertwo, &m_zs);

	// Player
	Weapon = new CWeaponlasercube(&playertwo);
	Weapon2 = new CWeaponlasercube(&playerone);

	// Soundtrack
	Soundtrack.Init("sound\\soundtrack.wav");
	m_zs.AddAudio(&Soundtrack);
	Soundtrack.Loop();
}



void CGame::Tick(float fTime, float fTimeDelta)
{	
	if (m_zdcur.ButtonDownLeft())
		if(m_zdcur.PickGeoPreselected(m_zgs) == &m_zTodesstern)
			m_AuraOn = !m_AuraOn;
	
	if (m_AuraOn) {
		m_zmTodesAura.SetTransparency(m_float);
		m_float-= 0.0002;
		if (m_float < 0.5)
			m_float = 0.5;
	}
	else {
		m_zmTodesAura.SetTransparency(m_float);
		m_float += 0.0002;
		if (m_float > 1)
			m_float = 1;
	}

	// Shift Key schneller bewegen
	if (m_zdk.KeyPressed(42))
	{
		m_zpCam.SetTranslationSensitivity(1000);
	}
	else
	{
		m_zpCam.SetTranslationSensitivity(100);
	}

	// Tick 
	m_zr.Tick(fTimeDelta);

	// Zoom "Z"
	// Sensitivity merken und auch zurücksetzen
 	if (m_zdk.KeyPressed(DIK_Y)) //121
	{
		m_zc.SetFov(HALFPI / 4);
		if (m_zfsens == 0) {
			m_zfsens = m_zpCam.GetRotationSensitivity();
		}
		m_zpCam.SetRotationSensitivity(0.2f);
	}
	else {
		m_zc.SetFov(HALFPI);
		if (m_zfsens != 0) {
			m_zpCam.SetRotationSensitivity(m_zfsens);
		}
		m_zfsens = 0;
	}

	// Easter Egg "F1"
	if (m_zdk.KeyDown(DIK_F1)) {
		sternbild = !sternbild;
		if (sternbild) {
			m_zpSonne.AddGeo(m_zSternenbild);
		}
		else {
			m_zpSonne.SubGeo(m_zSternenbild);
		}
	}

	// Third Person Perspektive für Raumschiff "F3"
	if (m_zdk.KeyDown(DIK_F3)) {
		m_zv.SetCamera(&m_zcschiffpl2);
		m_zbschiff = true;
	}
	// Zurück zur "normalen Cam" "F2"
	if (m_zdk.KeyDown(DIK_F2)) {
		m_zv.SetCamera(&m_zc);
		m_zbschiff = false;
	}

	// WASD Steuerung Keyboard
	if (m_zbschiff == true) {
		m_zdk.PlaceWASD(playerone, fTimeDelta);
	}
	else {
		m_zdk.PlaceWASD(m_zpCam, fTimeDelta);
	}

	// Schießen mit Leertaste 
	if (m_zdk.KeyDown(DIK_SPACE))
	{
		//Weapon2.Shoot(m_zpschiffpl2.GetDirection(), &m_zpschiffpl2, &m_zs); m_zprocketpl2  playertwo
 		Weapon->Shoot(playerone.GetDirection(), &playerone, &m_zs,&playertwo);
	}
	Weapon->Update(fTimeDelta);

	// Scheißen mit Button
	if (m_zdk.KeyDown(DIK_H))
	{
		//Weapon2.Shoot(m_zpschiffpl2.GetDirection(), &m_zpschiffpl2, &m_zs);
		Weapon2->Shoot(playertwo.GetDirection(), &playertwo, &m_zs,&playerone);
	}
	Weapon2->Update(fTimeDelta);

	// Bewegung mit Gamepad
	Bewegung();
	Drehung();
	if (m_zbschiffpl2 == true) {
		playertwo.Move(fTimeDelta, false, m_zxbew, m_zybew, m_zhoehe, m_zxrot, m_zyrot);

	}
	else {
		m_zpCam.Move(fTimeDelta, false, m_zxbew, m_zybew, m_zhoehe, m_zxrot, m_zyrot);

	}

	// Spotlight für Erde
	m_zperdespot.SetPointing(&m_zpErde);
	

	// Sonnen Rotation
	//m_zpSonne.RotateY(fTime/30);
	
	// Planeten Rotation
	// Merkur
	m_pMerkur->revolution(fTimeDelta);
	// Venus
	m_pVenus->revolution(fTimeDelta);
	// Erde
	m_zpErdrot.RotateY(fTime*3);
	m_zpErdrot.RotateXDelta(0.4188);
	m_zpErde.TranslateX(667);
	m_zpErde.RotateYDelta(0.1*fTime);
	// Mars
	m_pMars->revolution(fTimeDelta);
	// Jupiter
	m_pJupiter->revolution(fTimeDelta);
	// Saturn
	m_pSaturn->revolution(fTimeDelta);
	// Uranus
	m_pUranus->revolution(fTimeDelta);
	// Neptun
	m_pNeptun->revolution(fTimeDelta);
	// Monde
	m_zpErdmond.TranslateX(50);
	m_zpErdmond.RotateYDelta(fTime * 2);
	// Sateliten
	m_zpsat.RotateXDelta(fTimeDelta * 0.8);
	// Spotlight
	m_zperdespot.TranslateX(370);
	m_zperdespot.RotateYDelta(0.1*fTime);

	// Punkte Aufrufen
	playerone.zeigepunktean();
	playertwo.zeigepunktean();

	// Check Satelliten
	placer->CheckPlayers(fTimeDelta);

	// Check points
	StatusChecker();
}

void CGame::Fini()
{
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Fensterinhalt an Fenstergröße anpassen
	m_zf.ReSize(iNewWidth, iNewHeight);
}

// Gamepad Left Stick 
// Fehler analoges Signal abfangen 
// Sensitivity je nach Eingabe hoch bzw. runter stellen
void CGame::Bewegung() {

	if (m_zdc.GetRelativeX() > 0.3) {
		m_zxbew = 1;
		m_zpCam.m_fTranslationSensitivity = (float) 1.82901061 * 200 * m_zdc.GetRelativeX();
	}
	else if (m_zdc.GetRelativeX() < -0.3) {
		m_zxbew = -1;
		m_zpCam.m_fTranslationSensitivity = (float) 1.82901061 * 200 * -m_zdc.GetRelativeX();
	}
	else
		m_zxbew = 0;

	if (m_zdc.GetRelativeY() > 0.3) {
		m_zybew = 1;
		m_zpCam.m_fTranslationSensitivity = (float) 1.82901061 * 200 * m_zdc.GetRelativeY();
	}
	else if (m_zdc.GetRelativeY() < -0.3) {
		m_zybew = -1;
		m_zpCam.m_fTranslationSensitivity = (float) 1.82901061 * 200 * -m_zdc.GetRelativeY();
	}
	else
		m_zybew = 0;

}

// Gamepad Right Stick
void CGame::Drehung() {

	if (m_zdc.GetRelativeRX() > 0.3) {
		m_zxrot = 1;
		m_zpCam.m_fRotationSensitivity = (float) 1.82901061 *  m_zdc.GetRelativeRX();
	}
	else if (m_zdc.GetRelativeRX() < -0.3) {
		m_zxrot = -1;
		m_zpCam.m_fRotationSensitivity = (float) 1.82901061 *  -m_zdc.GetRelativeRX();
	}
	else
		m_zxrot = 0;

	if (m_zdc.GetRelativeRY() > 0.3) {
		m_zyrot = -1;
		m_zpCam.m_fRotationSensitivity = (float) 1.82901061 *  m_zdc.GetRelativeRY();
	}
	else if (m_zdc.GetRelativeRY() < -0.3) {
		m_zyrot = 1;
		m_zpCam.m_fRotationSensitivity = (float) 1.82901061 *  -m_zdc.GetRelativeRY();
	}
	else
		m_zyrot = 0;
}

void CGame::StatusChecker()
{
	if (playerone.checkpoints())
	{
		playerone.triggerverloren();
		playertwo.triggergewonnen();
	}
	else if (playertwo.checkpoints())
	{
		playerone.triggergewonnen();
		playertwo.triggerverloren();
	}
}