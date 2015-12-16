#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "GameData.h"
#include "Player.h"
#include "Player2.h"
#include "leftButton.h"
#include "rightButton.h"
#include "GameStates.h"
#include "TowerBase.h"
#include "TowerGun.h"
#include <string>
//#include "DPad.h"

class GameScreen : public cocos2d::Layer
{
private:
	std::vector<TowerBase *> m_towerBases; 
	std::string const TOWERS_SPRITE_BATCH = "TowerBases"; // don't forget to #include <string>

	std::vector<TowerGun *> m_traps;
	std::string const TRAPS_SPRITE_BATCH = "Traps"; // don't forget to #include <string>
	
	std::vector<leftButton *> m_leftButton;

	void createPlatforms();
	void createTraps();
	void createleftButton();

	Player * player;
	Player2 * player2;

	leftButton * left;
	rightButton * right;

	GameStates m_gameState; 
	TowerGun * m_towerGun;

	void showTower();

	cocos2d::PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);
	void GameScreen::MovementRight();
	void GameScreen::MovementLeft();
	void GameScreen::playerOneSelected();
	void GameScreen::playerTwoSelected();
	bool player1Selected;
	bool player2Selected;
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	//Camera

	//GameLoop Stuff! 
	void update(float dt);	// dt = delta time - the time between frames.

	//Destroy bases
	void destroyBases();

	//Dpad stuff
	//DPad *controller;

	void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

	CREATE_FUNC(GameScreen);
};