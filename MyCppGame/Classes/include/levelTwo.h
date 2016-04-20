#pragma once

#include "cocos2d.h"
#include <ui\CocosGUI.h>
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
#include "endGame.h"
#include "Button.h"
#include "FlameEmitter.h"

#include <string>
//#include "DPad.h"

class LevelTwo : public cocos2d::Layer
{
private:
	std::vector<TowerBase *> m_towerBases;
	std::string const TOWERS_SPRITE_BATCH = "TowerBases"; // don't forget to #include <string>

	std::vector<TowerGun *> m_traps;
	std::string const TRAPS_SPRITE_BATCH = "Traps"; // don't forget to #include <string>

	std::vector<endGame *> m_end;
	std::string const END_SPRITE_BATCH = "EndDoor"; // don't forget to #include <string>

	std::vector<Button *> m_button;
	std::string const BUTTON_SPRITE_BATCH = "EndDoor";

	std::vector<TowerBase *> m_hiddenPlats;
	std::string const HIDDEN_SPRITE_BATCH = "hiddenPlatforms";

	std::vector<TowerBase *> m_levelTwoPlat;
	std::string const LEVELTWO_SPRITE_BATCH = "levelTwoPlatforms";

	std::vector<TowerBase *> m_removablePlats;
	std::string const REMOVABLE_SPRITE_BATCH = "removablePlatforms";

	std::vector<FlameEmitter *> m_flameEmitter;
	std::string const FLAMEEMITTER_SPRITE_BATCH = "flameEmiiters";

	std::vector<leftButton *> m_leftButton;

	void createPlatforms();
	void createHiddenPlatforms();
	void createTraps();
	void createleftButton();
	void createEndGame();
	void createButton();
	void preloadAudio();
	void playAudio();
	void createEndGameJack();
	void createEndGameJill();
	void showEndGame();
	void createRemovablePlats();
	void createFlameEmiiter();
	void createFlames(float ft);
	void boundingBoxCollision();

	bool onContactBegin(cocos2d::PhysicsContact &contact);
	bool removeTraps;

	bool addPlatfroms = false;

	bool playerOneDead = false;
	bool playerTwoDead = false;

	bool playerOneEndGame = false;
	bool playerTwoEndGame = false;

	Player * player;
	bool p1Jumped = false;

	Player2 * player2;
	bool p2Jumped = false;

	bool playersColliding;
	bool playJumpSound;

	leftButton * left;
	rightButton * right;

	GameStates m_gameState;
	TowerGun * m_towerGun;

	TowerGun * trap;

	void showTower();

	cocos2d::PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	//Add event listeners for my buttons.
	void addEvents();
	void handleTouch(Ref *pSender);
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(float dt);
	//Camera
	cocos2d::Sprite *cameraTarget;
	cocos2d::Follow *camera;

	void MovementRight();
	void MovementLeft();
	void playerOneSelected();
	void playerTwoSelected();
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

	CREATE_FUNC(LevelTwo);
};