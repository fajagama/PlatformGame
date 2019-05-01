#include "LevelSetup.h"

#include <sstream>

#include "Level.h"
#include "SoundController.h"
#include "AnimationController.h"
#include "CharacterMoving.h"
#include "FixedPosition.h"

#include "ExitGame.h"
#include "Settings.h"
#include "SelectLevel.h"

#include "MusicVolumeUp.h"
#include "MusicVolumeDown.h"
#include "MusicVolume.h"

#include "SoundEffectVolume.h"
#include "SoundEffectVolumeDown.h"
#include "SoundEffectVolumeUp.h"

#include "Resolution1024.h"
#include "Resolution1360.h"
#include "Resolution1920.h"
#include "Fullscreen.h"

#include "BtnBack.h"

#include "LoadLevelOne.h"
#include "LoadLevelTwo.h"
#include "LoadLevelThree.h"

#include "LevelMenu.h"

#include "PlayerController.h"
#include "EndFlag.h"

#include "SoundManager.h"
#include "TimeManager.h"
#include "WindowManager.h"

void LevelSetup::run()
{
	Core coreEngine = Core("Platform game");

	/*
	*
	*	MAIN MENU LEVEL
	*
	*/

	Level mainMenuLevel = Level("main_menu");

	RenderImage backgroundImage = RenderImage("assets/background.png");
	GameObject backgoundGO = GameObject(7500, 7500);
	backgoundGO.addComponent(backgroundImage);
	backgoundGO.setZIndex(-1);
	backgoundGO.setPosition(-2500, -2500);

	RenderImage startBtnImage = RenderImage("assets/start.png");
	SelectLevel selectLevel = SelectLevel();
	GameObject startBtnGO = GameObject(300, 100);
	startBtnGO.addComponent(startBtnImage);
	startBtnGO.addComponent(selectLevel);
	startBtnGO.setPosition(0, 0);

	RenderImage settingsBtnImage = RenderImage("assets/settings.png");
	Settings settings = Settings();
	GameObject settingsBtnGO = GameObject("settingsBtn", 300, 100);
	settingsBtnGO.addComponent(settingsBtnImage);
	settingsBtnGO.addComponent(settings);
	settingsBtnGO.setPosition(0, 125);

	RenderImage exitBtnImage = RenderImage("assets/exit.png");
	ExitGame exitGame = ExitGame();
	GameObject exitBtnGO = GameObject(300, 100);
	exitBtnGO.addComponent(exitBtnImage);
	exitBtnGO.addComponent(exitGame);
	exitBtnGO.setPosition(0, 250);

	mainMenuLevel.addGameObject(backgoundGO);
	mainMenuLevel.addGameObject(startBtnGO);
	mainMenuLevel.addGameObject(settingsBtnGO);
	mainMenuLevel.addGameObject(exitBtnGO);

	mainMenuLevel.cameraFollow("settingsBtn");

	coreEngine.addLevel(mainMenuLevel);
	coreEngine.loadLevel("main_menu");

	/*
	*
	*	SETTINGS LEVEL
	*
	*/

	Level settingsLevel = Level("settings");

	RenderImage musicImage = RenderImage("assets/music.png");
	GameObject musicGO = GameObject(300, 100);
	musicGO.addComponent(musicImage);

	RenderImage musicPlusImage = RenderImage("assets/plus.png");
	MusicVolumeUp musicVolumeUp = MusicVolumeUp();
	GameObject musicPlusGO = GameObject(100, 100);
	musicPlusGO.addComponent(musicPlusImage);
	musicPlusGO.addComponent(musicVolumeUp);
	musicPlusGO.setPosition(510, 0);

	RenderImage musicMinusImage = RenderImage("assets/minus.png");
	GameObject musicMinusGO = GameObject(100, 100);
	MusicVolumeDown musicVolumeDown = MusicVolumeDown();
	musicMinusGO.addComponent(musicMinusImage);
	musicMinusGO.addComponent(musicVolumeDown);
	musicMinusGO.setPosition(310, 0);

	RenderImage musicVolumeImage = RenderImage("assets/100.png");
	GameObject musicVolumeGO = GameObject(100, 100);
	MusicVolume musicVolume = MusicVolume();
	musicVolumeGO.addComponent(musicVolumeImage);
	musicVolumeGO.addComponent(musicVolume);
	musicVolumeGO.setPosition(410, 0);

	RenderImage soundEffectImage = RenderImage("assets/sound-effect.png");
	GameObject soundEffectGO = GameObject(300, 100);
	soundEffectGO.setPosition(0, 110);
	soundEffectGO.addComponent(soundEffectImage);

	SoundController soundEffectCountroller = SoundController();
	soundEffectCountroller.add("ding", "assets/ding.wav");

	RenderImage soundEffectPlusImage = RenderImage("assets/plus.png");
	SoundEffectVolumeUp soundEffectVolumeUp = SoundEffectVolumeUp();
	GameObject soundEffectPlusGO = GameObject(100, 100);
	soundEffectPlusGO.addComponent(soundEffectPlusImage);
	soundEffectPlusGO.addComponent(soundEffectVolumeUp);
	soundEffectPlusGO.addComponent(soundEffectCountroller);
	soundEffectPlusGO.setPosition(510, 110);

	RenderImage soundEffectMinusImage = RenderImage("assets/minus.png");
	SoundEffectVolumeDown soundEffectVolumeDown = SoundEffectVolumeDown();
	GameObject soundEffectMinusGO = GameObject(100, 100);
	soundEffectMinusGO.addComponent(soundEffectMinusImage);
	soundEffectMinusGO.addComponent(soundEffectVolumeDown);
	soundEffectMinusGO.addComponent(soundEffectCountroller);
	soundEffectMinusGO.setPosition(310, 110);

	RenderImage soundEffectVolumeImage = RenderImage("assets/100.png");
	GameObject soundEffectVolumeGO = GameObject(100, 100);
	SoundEffectVolume soundEffectVolume = SoundEffectVolume();
	soundEffectVolumeGO.addComponent(soundEffectVolumeImage);
	soundEffectVolumeGO.addComponent(soundEffectVolume);
	soundEffectVolumeGO.setPosition(410, 110);

	RenderImage fullscreenImage = RenderImage("assets/fullscreen.png");
	GameObject fullscreenGO = GameObject(300, 100);
	fullscreenGO.setPosition(0, 220);
	fullscreenGO.addComponent(fullscreenImage);

	RenderImage fullscreenCheckImage = RenderImage("assets/empty.png");
	Fullscreen fullscreen = Fullscreen();
	GameObject fullscreenCheckGO = GameObject(100, 100);
	fullscreenCheckGO.setPosition(410, 220);
	fullscreenCheckGO.addComponent(fullscreenCheckImage);
	fullscreenCheckGO.addComponent(fullscreen);

	RenderImage resolutionImage = RenderImage("assets/resolution.png");
	GameObject resolutionGO = GameObject(300, 100);
	resolutionGO.setPosition(0, 330);
	resolutionGO.addComponent(resolutionImage);

	RenderImage resolution1024Image = RenderImage("assets/1024.png");
	Resolution1024 resolution1024 = Resolution1024();
	GameObject resolution1024GO = GameObject(300, 100);
	resolution1024GO.setPosition(310, 330);
	resolution1024GO.addComponent(resolution1024Image);
	resolution1024GO.addComponent(resolution1024);

	RenderImage resolution1360Image = RenderImage("assets/1360.png");
	Resolution1360 resolution1360 = Resolution1360();
	GameObject resolution1360GO = GameObject(300, 100);
	resolution1360GO.setPosition(310, 430);
	resolution1360GO.addComponent(resolution1360Image);
	resolution1360GO.addComponent(resolution1360);

	RenderImage resolution1920Image = RenderImage("assets/1920.png");
	Resolution1920 resolution1920 = Resolution1920();
	GameObject resolution1920GO = GameObject(300, 100);
	resolution1920GO.setPosition(310, 530);
	resolution1920GO.addComponent(resolution1920Image);
	resolution1920GO.addComponent(resolution1920);

	RenderImage backImage = RenderImage("assets/back.png");
	BtnBack btnBack = BtnBack();
	GameObject backGO = GameObject(300, 100);
	backGO.setPosition(155, 640);
	backGO.addComponent(backImage);
	backGO.addComponent(btnBack);

	GameObject settingCenterGO = GameObject("settingsCenter", 1, 1);
	settingCenterGO.setPosition(305, 370);

	settingsLevel.addGameObject(backgoundGO);

	settingsLevel.addGameObject(musicGO);
	settingsLevel.addGameObject(musicPlusGO);
	settingsLevel.addGameObject(musicMinusGO);
	settingsLevel.addGameObject(musicVolumeGO);

	settingsLevel.addGameObject(soundEffectGO);
	settingsLevel.addGameObject(soundEffectPlusGO);
	settingsLevel.addGameObject(soundEffectMinusGO);
	settingsLevel.addGameObject(soundEffectVolumeGO);

	settingsLevel.addGameObject(fullscreenGO);
	settingsLevel.addGameObject(fullscreenCheckGO);

	settingsLevel.addGameObject(resolutionGO);
	settingsLevel.addGameObject(resolution1024GO);
	settingsLevel.addGameObject(resolution1360GO);
	settingsLevel.addGameObject(resolution1920GO);

	settingsLevel.addGameObject(backGO);

	settingsLevel.addGameObject(settingCenterGO);
	settingsLevel.cameraFollow("settingsCenter");

	coreEngine.addLevel(settingsLevel);

	/*
	*
	*	SELECT LEVEL
	*
	*/

	Level selectLevelLevel = Level("select_level");

	RenderImage level1Image = RenderImage("assets/level1.png");
	LoadLevelOne loadLevel1 = LoadLevelOne();
	GameObject level1GO = GameObject(300, 100);
	level1GO.addComponent(level1Image);
	level1GO.addComponent(loadLevel1);
	level1GO.setPosition(0, -110);

	RenderImage level2Image = RenderImage("assets/level2.png");
	LoadLevelTwo loadLevel2 = LoadLevelTwo();
	GameObject level2GO = GameObject("level2", 300, 100);
	level2GO.addComponent(level2Image);
	level2GO.addComponent(loadLevel2);
	level2GO.setPosition(0, 0);

	RenderImage level3Image = RenderImage("assets/level3.png");
	LoadLevelThree loadLevel3 = LoadLevelThree();
	GameObject level3GO = GameObject(300, 100);
	level3GO.addComponent(level3Image);
	level3GO.addComponent(loadLevel3);
	level3GO.setPosition(0, 110);

	RenderImage backSelectLevelImage = RenderImage("assets/back.png");
	BtnBack btnBackSelectLevel = BtnBack();
	GameObject backSelectLevelGO = GameObject(300, 100);
	backSelectLevelGO.setPosition(0, 220);
	backSelectLevelGO.addComponent(backSelectLevelImage);
	backSelectLevelGO.addComponent(btnBackSelectLevel);

	selectLevelLevel.addGameObject(backgoundGO);
	selectLevelLevel.addGameObject(level1GO);
	selectLevelLevel.addGameObject(level2GO);
	selectLevelLevel.addGameObject(level3GO);
	selectLevelLevel.addGameObject(backSelectLevelGO);

	selectLevelLevel.cameraFollow("level2");

	coreEngine.addLevel(selectLevelLevel);

	/*******************************************************************/

	/*
	*
	*	LEVEL ONE
	*
	*/

	Level levelOne = Level("level_one");

	GameObject playerGO = GameObject("player", 45, 52);
	Collider playerCollider = Collider(45, 52);
	SimpleGravity playerGravity = SimpleGravity();
	PlayerController testCom = PlayerController();
	playerGravity.setWeight(15);

	Sprite playerSprite = Sprite("assets/player-animation.png", 9, 14);
	Animation playerTextureStand = Animation(playerSprite, 1);
	playerTextureStand.addFrame(0, 0);
	playerTextureStand.addFrame(1, 0);

	Animation playerTextureJump = Animation(playerSprite, 1);
	playerTextureJump.addFrame(2, 0);

	Animation playerTextureWalk = Animation(playerSprite, 0.5);
	playerTextureWalk.addFrame(3, 0);
	playerTextureWalk.addFrame(4, 0);

	AnimationController animationController = AnimationController();
	animationController.add("stand", playerTextureStand);
	animationController.add("jump", playerTextureJump);
	animationController.add("walk", playerTextureWalk);

	SoundController soundController = SoundController();
	soundController.add("coin", "assets/coin.wav");
	soundController.add("jump", "assets/jump.wav");

	CharacterMoving moving = CharacterMoving(25, 30);

	playerGO.addComponent(playerCollider);
	playerGO.addComponent(moving);
	playerGO.addComponent(playerGravity);
	playerGO.addComponent(testCom);
	playerGO.addComponent(soundController);
	playerGO.addComponent(animationController);

	playerGO.setPosition(1150, 350);

	/*
	*	Ground
	*/

	const int mapRows = 25;
	const int mapCols = 76;

	int map[mapRows][mapCols] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,4,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,4,1,1,3,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,5,5,5,2,0,8,0,0,0,0,0,4,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,4,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0 },
	};

	makeLevel(levelOne, map);

	GameObject pauseMenuGO = GameObject("pause", 400, 400);
	RenderImage pauseMenuImg = RenderImage("assets/pause.png");
	FixedPosition fixedPositionPauseMenu = FixedPosition(Spot::CENTER);
	pauseMenuGO.setZIndex(10);
	pauseMenuGO.addComponent(fixedPositionPauseMenu);
	pauseMenuGO.addComponent(pauseMenuImg);
	pauseMenuGO.setActive(false);

	GameObject levelMenuGO = GameObject(1, 1);
	LevelMenu levelMenu = LevelMenu();
	levelMenuGO.addComponent(levelMenu);

	RenderImage backImagelevelMenu = RenderImage("assets/exit.png");
	BtnBack btnBacklevelMenu = BtnBack();
	FixedPosition btnBacklevelMenufixedPosition = FixedPosition(Spot::CENTER);
	btnBacklevelMenufixedPosition.setOffsetY(110);
	GameObject btnBackToMenu = GameObject("back", 300, 100);
	btnBackToMenu.setZIndex(20);
	btnBackToMenu.addComponent(btnBacklevelMenu);
	btnBackToMenu.addComponent(backImagelevelMenu);
	btnBackToMenu.addComponent(btnBacklevelMenufixedPosition);
	btnBackToMenu.setActive(false);

	RenderImage resumeImagelevelMenu = RenderImage("assets/resume.png");
	LevelMenu resumeLevelMenu = LevelMenu();
	FixedPosition resumelevelMenufixedPosition = FixedPosition(Spot::CENTER);
	GameObject resumeBackToGame = GameObject("resume", 300, 100);
	resumeBackToGame.setZIndex(20);
	resumeBackToGame.addComponent(resumeImagelevelMenu);
	resumeBackToGame.addComponent(resumeLevelMenu);
	resumeBackToGame.addComponent(resumelevelMenufixedPosition);
	resumeBackToGame.setActive(false);

	RenderImage endDialogImage = RenderImage("assets/level-complete.png");
	FixedPosition endDialogPosition = FixedPosition(Spot::CENTER);
	endDialogPosition.setOffsetY(-30);
	GameObject endDialogGO = GameObject("dialog", 500, 500);
	endDialogGO.setZIndex(10);
	endDialogGO.addComponent(endDialogImage);
	endDialogGO.addComponent(endDialogPosition);
	endDialogGO.setActive(false);

	RenderImage nextLevelCompleteImage = RenderImage("assets/next-level.png");
	FixedPosition nextLevelCompleteFixedPosition = FixedPosition(Spot::CENTER);
	GameObject nextLevelGO = GameObject("next_level", 300, 100);
	nextLevelGO.setZIndex(20);
	nextLevelGO.addComponent(nextLevelCompleteFixedPosition);
	nextLevelGO.addComponent(nextLevelCompleteImage);
	nextLevelGO.addComponent(loadLevel2);
	nextLevelGO.setActive(false);

	RenderImage timeZeroImage = RenderImage("assets/number-0.png");
	RenderImage timeColonImage = RenderImage("assets/number-colon.png");

	FixedPosition timeOnePostion = FixedPosition(Spot::CENTER);
	timeOnePostion.setOffsetY(-125);
	timeOnePostion.setOffsetX(-50);

	GameObject timeOneGO = GameObject("time_one", 25, 30);
	timeOneGO.setZIndex(20);
	timeOneGO.addComponent(timeZeroImage);
	timeOneGO.addComponent(timeOnePostion);
	timeOneGO.setActive(false);

	FixedPosition timeTwoPostion = FixedPosition(Spot::CENTER);
	timeTwoPostion.setOffsetY(-125);
	timeTwoPostion.setOffsetX(-25);

	GameObject timeTwoGO = GameObject("time_two", 25, 30);
	timeTwoGO.setZIndex(20);
	timeTwoGO.addComponent(timeZeroImage);
	timeTwoGO.addComponent(timeTwoPostion);
	timeTwoGO.setActive(false);

	FixedPosition timeColonPostion = FixedPosition(Spot::CENTER);
	timeColonPostion.setOffsetY(-125);

	GameObject timeColonGO = GameObject("time_colon", 25, 30);
	timeColonGO.setZIndex(20);
	timeColonGO.addComponent(timeColonImage);
	timeColonGO.addComponent(timeColonPostion);
	timeColonGO.setActive(false);

	FixedPosition timeThreePostion = FixedPosition(Spot::CENTER);
	timeThreePostion.setOffsetY(-125);
	timeThreePostion.setOffsetX(25);

	GameObject timeThreeGO = GameObject("time_three", 25, 30);
	timeThreeGO.setZIndex(20);
	timeThreeGO.addComponent(timeZeroImage);
	timeThreeGO.addComponent(timeThreePostion);
	timeThreeGO.setActive(false);

	FixedPosition timeFourPostion = FixedPosition(Spot::CENTER);
	timeFourPostion.setOffsetY(-125);
	timeFourPostion.setOffsetX(50);

	GameObject timeFourGO = GameObject("time_four", 25, 30);
	timeFourGO.setZIndex(20);
	timeFourGO.addComponent(timeZeroImage);
	timeFourGO.addComponent(timeFourPostion);
	timeFourGO.setActive(false);

	RenderImage scoreImage = RenderImage("assets/score-0.png");
	FixedPosition scoreFixedPosition = FixedPosition(Spot::TOP_RIGHT);
	GameObject scorelGO = GameObject("score", 176, 75);
	scorelGO.setZIndex(20);
	scorelGO.addComponent(scoreImage);
	scorelGO.addComponent(scoreFixedPosition);

	levelOne.addGameObject(nextLevelGO);
	levelOne.addGameObject(endDialogGO);
	levelOne.addGameObject(resumeBackToGame);
	levelOne.addGameObject(levelMenuGO);
	levelOne.addGameObject(pauseMenuGO);
	levelOne.addGameObject(btnBackToMenu);
	levelOne.addGameObject(backgoundGO);
	levelOne.addGameObject(scorelGO);

	levelOne.addGameObject(timeOneGO);
	levelOne.addGameObject(timeTwoGO);
	levelOne.addGameObject(timeColonGO);
	levelOne.addGameObject(timeThreeGO);
	levelOne.addGameObject(timeFourGO);

	levelOne.addGameObject(playerGO);
	levelOne.cameraFollow(playerGO.getName());

	coreEngine.addLevel(levelOne);

	/*******************************************************************/

	/*
	*
	*	LEVEL TWO
	*
	*/

	Level levelTwo = Level("level_two");

	/*
	*	Ground
	*/

	const int mapRowsTwo = 25;
	const int mapColsTwo = 76;

	int mapTwo[mapRowsTwo][mapColsTwo] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,4,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	};

	makeLevel(levelTwo, mapTwo);

	GameObject nextLevelTwoGO = GameObject("next_level", 300, 100);
	nextLevelTwoGO.setZIndex(20);
	nextLevelTwoGO.addComponent(nextLevelCompleteFixedPosition);
	nextLevelTwoGO.addComponent(nextLevelCompleteImage);
	nextLevelTwoGO.addComponent(loadLevel3);
	nextLevelTwoGO.setActive(false);

	levelTwo.addGameObject(nextLevelTwoGO);

	levelTwo.addGameObject(endDialogGO);
	levelTwo.addGameObject(resumeBackToGame);
	levelTwo.addGameObject(levelMenuGO);
	levelTwo.addGameObject(pauseMenuGO);
	levelTwo.addGameObject(btnBackToMenu);
	levelTwo.addGameObject(backgoundGO);
	levelTwo.addGameObject(scorelGO);

	levelTwo.addGameObject(timeOneGO);
	levelTwo.addGameObject(timeTwoGO);
	levelTwo.addGameObject(timeColonGO);
	levelTwo.addGameObject(timeThreeGO);
	levelTwo.addGameObject(timeFourGO);

	playerGO.setPosition(1150, 450);

	levelTwo.addGameObject(playerGO);
	levelTwo.cameraFollow(playerGO.getName());

	coreEngine.addLevel(levelTwo);

	/*******************************************************************/


	/*
	*
	*	LEVEL THREE
	*
	*/

	Level levelThree = Level("level_three");

	/*.*	Ground
	*/

	const int mapRowsThree = 25;
	const int mapColsThree = 76;

	int mapThree[mapRowsThree][mapColsThree] = {
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,4,3,0,0,0,0,8,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,0,0,6,2,0,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,0,0,0,4,1,5,5,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,4,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,4,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,0,0,0,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
	};

	makeLevel(levelThree, mapThree);

	levelThree.addGameObject(endDialogGO);
	levelThree.addGameObject(resumeBackToGame);
	levelThree.addGameObject(levelMenuGO);
	levelThree.addGameObject(pauseMenuGO);
	levelThree.addGameObject(btnBackToMenu);
	levelThree.addGameObject(backgoundGO);
	levelThree.addGameObject(scorelGO);

	levelThree.addGameObject(timeOneGO);
	levelThree.addGameObject(timeTwoGO);
	levelThree.addGameObject(timeColonGO);
	levelThree.addGameObject(timeThreeGO);
	levelThree.addGameObject(timeFourGO);

	playerGO.setPosition(1100, 600);

	levelThree.addGameObject(playerGO);
	levelThree.cameraFollow(playerGO.getName());

	coreEngine.addLevel(levelThree);

	/*******************************************************************/

	coreEngine.run();
}

void LevelSetup::makeLevel(Level & level, int map[25][76])
{
	/*
	*	Flag
	*/

	RenderImage flagImage = RenderImage("assets/flag.png");
	EndFlag endFlag = EndFlag();
	Collider flagCollider = Collider(50, 50);
	flagCollider.setTrigger(true);
	GameObject flagGO = GameObject("flag", 50, 50);
	flagGO.addComponent(flagImage);
	flagGO.addComponent(endFlag);
	flagGO.addComponent(flagCollider);

	/*
	*	Coin
	*/

	Sprite sprite = Sprite("assets/coin2.png", 16, 16);
	Animation animation = Animation(sprite, 0.1);
	animation.addFrame(0, 0);
	animation.addFrame(1, 0);
	animation.addFrame(2, 0);
	animation.addFrame(3, 0);
	animation.addFrame(4, 0);
	animation.addFrame(3, 0);
	animation.addFrame(2, 0);
	animation.addFrame(1, 0);

	Collider coinCollider = Collider(50, 50);
	coinCollider.setTrigger(true);

	/************************/

	RenderImage groundTopTexture = RenderImage("assets/teren-top.png");
	RenderImage groundMiddleTexture = RenderImage("assets/teren-middle.png");
	RenderImage groundWallLeftTexture = RenderImage("assets/teren-wall-left.png");
	RenderImage groundWallRightTexture = RenderImage("assets/teren-wall-right.png");
	RenderImage groundCorverLeftTexture = RenderImage("assets/teren-corner-left.png");
	RenderImage groundCornerRightTexture = RenderImage("assets/teren-corner-right.png");

	Collider groundCollider = Collider(50, 50);
	Collider platformCollider = Collider(50, 20);

	int coins = 0;

	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 76; y++)
		{
			if (map[x][y] >= 1 && 6 >= map[x][y]) {
				GameObject groundGO = GameObject(50, 50);
				switch (map[x][y])
				{
				case 1:
					groundGO.addComponent(groundTopTexture);
					break;
				case 2:
					groundGO.addComponent(groundWallRightTexture);
					break;
				case 3:
					groundGO.addComponent(groundCornerRightTexture);
					break;
				case 4:
					groundGO.addComponent(groundCorverLeftTexture);
					break;
				case 5:
					groundGO.addComponent(groundMiddleTexture);
					break;
				case 6:
					groundGO.addComponent(groundWallLeftTexture);
					break;
				}
				if (map[x][y] != 5) {
					groundGO.addComponent(groundCollider);
				}
				groundGO.setPosition(50 * y, 50 * x);
				level.addGameObject(groundGO);
			}
			if (map[x][y] == 8) {
				stringstream ss;
				ss << "coin" << (++coins);
				GameObject coinGO = GameObject(ss.str(), 50, 50);
				coinGO.setTag("coin");
				coinGO.addComponent(animation);
				coinGO.addComponent(coinCollider);
				coinGO.setPosition(50 * y, 50 * x);
				coinGO.setZIndex(1);
				level.addGameObject(coinGO);
			}
			if (map[x][y] == 9) {
				flagGO.setPosition(50 * y, 50 * x);
			}
		}
	}

	level.addGameObject(flagGO);
}
