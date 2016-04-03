#include "GameScene.h"
#include "Player.h"
#include "Player2.h"
#include "leftButton.h"
#include "rightButton.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//scene->getPhysicsWorld()->setGravity(Vec2(0, -9.81f));
	auto layer = GameScreen::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	
	
	return scene;
}

void GameScreen::activatePauseScene(Ref *pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScreen::activateGameOverScene(float dt)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameScreen::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto backgroundSprite = Sprite::create
		(ptr->m_backgroundTextureFile);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) +
		origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}

void GameScreen::playerOneSelected() {
	player1Selected = true;
	player2Selected = false;
}

void GameScreen::playerTwoSelected() {
	player1Selected = false;
	player2Selected = true;
}

void GameScreen::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{

}

void GameScreen::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
	CCLOG("MultiTouch has Moved!");
}

void GameScreen::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
	CCLOG("MultiTouch has Ended!");
}

void GameScreen::createPlatforms()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	SpriteBatchNode* spritebatch = SpriteBatchNode::create(ptr->m_textureAtlasImageFile);

	for (int i = 0; i < ptr->m_numberOfTowerBases; i++)
	{
		TowerBase * base = TowerBase::create(Vec2(ptr->m_towerBaseX[i], ptr->m_towerBaseY[i]), m_gameState);
		m_towerBases.push_back(base);
		spritebatch->addChild(base, -5);
	}
	this->addChild(spritebatch, 1, TOWERS_SPRITE_BATCH);
}

void GameScreen::createHiddenPlatforms()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	SpriteBatchNode* spritebatch = SpriteBatchNode::create(ptr->m_textureAtlasImageFile);

	for (int i = 0; i < ptr->m_numberOfHiddenPlatforms; i++)
	{
		TowerBase * HiddenPlat = TowerBase::create(Vec2(ptr->m_hiddenPlatsX[i], ptr->m_hiddenPlatsY[i]), m_gameState);
		m_hiddenPlats.push_back(HiddenPlat);
		spritebatch->addChild(HiddenPlat, -5);
	}
	this->addChild(spritebatch, 1, HIDDEN_SPRITE_BATCH);
}


void GameScreen::createTraps() 
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	SpriteBatchNode* spritebatch = SpriteBatchNode::create(ptr->m_textureAtlasImageFile);
	for (int i = 0; i < ptr->m_numberOfTraps; i++)
	{
		TowerGun * traps = TowerGun::create(Vec2(ptr->m_trapX[i], ptr->m_trapY[i]));
		m_traps.push_back(traps);
		spritebatch->addChild(traps, -5);
	}
	this->addChild(spritebatch, 1, TRAPS_SPRITE_BATCH);
}

void GameScreen::createEndGame()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	SpriteBatchNode* spritebatch = SpriteBatchNode::create(ptr->m_textureAtlasImageFile);
	for (int i = 0; i < ptr->m_numEndGame; i++)
	{
		endGame * endGame = endGame::create(Vec2(ptr->m_endGameX[i], ptr->m_endGameY[i]));
		m_end.push_back(endGame);
		spritebatch->addChild(endGame, -5);
	}
	this->addChild(spritebatch, 1, END_SPRITE_BATCH);
}

void GameScreen::createButton()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	SpriteBatchNode* spritebatch = SpriteBatchNode::create(ptr->m_textureAtlasImageFile);
	for (int i = 0; i < ptr->m_numButton; i++)
	{
		Button * button = Button::create(Vec2(ptr->m_endGameX[i], ptr->m_endGameY[i]));
		m_button.push_back(button);
		spritebatch->addChild(button, -5);
	}
	this->addChild(spritebatch, 1, END_SPRITE_BATCH);
}

//Update for GameLoop
void GameScreen::update(float dt)
{
	switch (m_gameState)
	{
	case GameStates::GameInit:
		showTower();        // add this
		destroyBases();     // add this
		break;
	case GameStates::GameRunning:
		break;
	default:
		break;
	}
}

void GameScreen::destroyBases()
{
	cocos2d::Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	this->removeChildByName(TOWERS_SPRITE_BATCH, true);
	m_towerBases.clear();
	m_towerBases.shrink_to_fit();
}

void GameScreen::showTower()
{
	Vec2 loc(0, 0);
	for (int i = 0; i < m_towerBases.size(); i++)
	{
		if (m_towerBases.at(i)->isTouched())
		{
			loc = m_towerBases.at(i)->getPosition();
		}
	}
	m_towerGun = TowerGun::create(loc);
	this->addChild(m_towerGun);
	m_gameState = GameStates::GameRunning;
}


bool GameScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//Audio stuff created here. 
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/main.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/main.mp3", true);

	//GameState initial setting.
	m_gameState = GameStates::PlaceGunTower;
	//Listeners for touch events created.
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameScreen::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScreen::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScreen::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	bool dir;
	bool jump = true;
	bool removeTraps = false;

	//Edge body created. Adding screen Boundry. 
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	//Pause Button Creation
	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
			"GameScreen/Pause_Button(Click).png",
			CC_CALLBACK_1(GameScreen::activatePauseScene, this));

	//Set Pause button position
	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));
	//Attach the pause button to the screen
	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	
	//.........................................................................................
	//DPad
	//LeftButton to move the player.
	auto leftbutton = ui::Button::create("GameScreen/leftButtonIdle.png",
		"GameScreen/leftbuttonActive.png");
	leftbutton->setPosition(Vec2(origin.x + visibleSize.width / 10,
		origin.y + visibleSize.height / 6));

	leftbutton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			//handleTouch(this);
			//player->getPhysicsBody()->applyForce(Vec2(1000, 0));
			//player->getPhysicsBody()->setDynamic(true);
			dir = true;
			if (player1Selected == true) {
				player->pMovement(player, dir);
			}
			if (player2Selected == true) {
				player2->p2Movement(player2, dir);
			}
			break;
		case ui::Widget::TouchEventType::ENDED:
			player->getPhysicsBody()->setVelocity(Vec2(0, 0));
			player2->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
	});

	this->addChild(leftbutton, 10);

	//RightButton to move the player.
	auto rightbutton = ui::Button::create("GameScreen/rightButtonIdle.png",
		"GameScreen/rightbuttonActive.png");
	rightbutton->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height / 6));

	rightbutton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			//handleTouch(this);
			//player->getPhysicsBody()->applyForce(Vec2(1000, 0));
			dir = false;
			if (player1Selected == true) {
				player->pMovement(player, dir);
			}
			if (player2Selected == true) {
				player2->p2Movement(player2, dir);
			}
			break;
		case ui::Widget::TouchEventType::ENDED:
			player->getPhysicsBody()->setVelocity(Vec2(0, 0));
			player2->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
	});

	this->addChild(rightbutton, 10);

	int stop;

	//JumpButton to move the player.
	auto jumpbutton = ui::Button::create("GameScreen/jumpButtonIdle.png",
		"GameScreen/jumpButtonActive.png");
	jumpbutton->setPosition(Vec2(origin.x + visibleSize.width - 100,
		origin.y + visibleSize.height / 6));
	jumpbutton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			//handleTouch(this);
			CCLOG("Jump button has been pressed");
			//player->getPhysicsBody()->applyForce(Vec2(1000, 0));
			if (player1Selected == true) {
				CCLOG("I've entered the jump if statement!");
				player->pJump(player);
				
			}
			if (player2Selected == true) {
				CCLOG("I've entered the jump if statement!");
				player2->p2Jump(player2);
			}
			break;
		case ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});

	this->addChild(jumpbutton, 10);
	addEvents();
	/*TowerBase * base = TowerBase::create(Vec2(ptr->m_towerBaseX[i], ptr->m_towerBaseY[i]), m_gameState);
		m_towerBases.push_back(base);
		spritebatch->addChild(base, -5);*/
	
	//Player select
	auto p1Select =
		MenuItemImage::create("GameScreen/p1Idle.png",
			"GameScreen/p1Select.png",
			CC_CALLBACK_0(GameScreen::playerOneSelected, this));

	p1Select->setPosition(Vec2((origin.x + visibleSize.width / 2) - 20,
		origin.y + visibleSize.height / 10));
	//this->addChild(p1Select, 5);

	auto p2Select =
		MenuItemImage::create("GameScreen/p2Idle.png",
			"GameScreen/p2Select.png",
			CC_CALLBACK_0(GameScreen::playerTwoSelected, this));

	p2Select->setPosition(Vec2((origin.x + visibleSize.width / 2) + 20,
		origin.y + visibleSize.height / 10));

	auto selectMenu = Menu::create(p1Select, p2Select, NULL);
	selectMenu->setPosition(Point::ZERO);
	this->addChild(selectMenu, 5);

	//Player Stuff Just testing stuff. Cut me some slack, Man!
	//Player One creation g and attachment ot the scene
	//Check player.cpp for Physics details.
	player = Player::create();

	this->addChild(player, 5);	

	//Same comment applies for player two as player one!
	player2 = Player2::create();
	this->addChild(player2, 5);
	
	//BackGround
	addBackGroundSprite(visibleSize, origin);

	//Create the Tower base. I'll be repurposing these for my level bases! 
	//Needs to be done urgently! 
	createPlatforms();
	createTraps();
	createEndGame();
	createButton();

	if (addPlatfroms == true)
	{
		createHiddenPlatforms();
	}

	/*if (removeTraps == true)
	{
		CCLOG("Remove traps has been entered");
		removeTraps = false;
	}*/
	//this calls an update everyloop. Essentially creating your game loop!
	//Please see "GameScene.h" for more info.
	this->scheduleUpdate();

	auto contactListener = EventListenerPhysicsContact::create();

	contactListener->onContactBegin = CC_CALLBACK_1(GameScreen::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	return true;
}

void GameScreen::addEvents()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener1 = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener1->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener1->onTouchBegan = [this](Touch* touch, Event* event) {
		//this->m_pos = touch->getLocation();
		//updateState();
		return true;
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, 30);
}

bool GameScreen::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if ((nodeA&&nodeB))
	{
		if ((nodeA->getTag() == 10))
		{
			if (nodeB->getTag() == 20)
			{
				//trap->removeTrap(trap);
				//removeTraps = true;
				//m_traps->
				//nodeB->removeFromParentAndCleanup(true);
				for (int i = 0; i < m_traps.size(); i++)
				{
					auto trap = m_traps.at(i);
					Director::getInstance()->getRunningScene()->removeChild(trap);
					//iter = m_projectiles.erase(iter);
					delete m_traps.at(i);
					//m_traps[i]->removeFromParentAndCleanup(true);
					addPlatfroms = true;
				}	
				m_traps.clear();
				//GameScreen::addPlatfroms = true;
			}
		}

		if ((nodeA->getTag() == 20))
		{
			if (nodeB->getTag() == 10)
			{
				//nodeA->removeFromParentAndCleanup(true);
			}
		}
		//return addPlatfroms;
	}
	


	//check if the bodies have collided.
	if ((0x000001 == a->getCollisionBitmask() && 0x000006 == b->getCollisionBitmask()) || (0x000006 == a->getCollisionBitmask() && 0x000001 == b->getCollisionBitmask()))
	{
		CCLOG("Collision has occured between Jack and the door!");
		//pButton->setSpriteFrame(ptr->m_buttonPressed);
		this->scheduleOnce(schedule_selector(GameScreen::activateGameOverScene), 1.0f);
	}

	if ((0x000001 == a->getCollisionBitmask() && 0x000005 == b->getCollisionBitmask()) || (0x000005 == a->getCollisionBitmask() && 0x000001 == b->getCollisionBitmask()))
	{
		CCLOG("Collision has occured between jack and the button!");
		for (int i = 0; i < m_traps.size(); i++)
		{
			auto trap = m_traps.at(i);

			sceneWorld->removeBody(trap->getPhysicsBody());

			Director::getInstance()->getRunningScene()->removeChild(trap);
			m_traps[i]->removeFromParentAndCleanup(true);
		}
		m_traps.clear();
		GameScreen::addPlatfroms = true;
		//pButton->setSpriteFrame(ptr->m_buttonPressed);
	}

	if ((0x000001 == a->getCollisionBitmask() && 0x000004 == b->getCollisionBitmask()) || (0x000004 == a->getCollisionBitmask() && 0x000001 == b->getCollisionBitmask()))
	{
		player->respawnPoint(player);
		CCLOG("Collision has occured between jack and the trap!");
		//pButton->setSpriteFrame(ptr->m_buttonPressed);
	}
	return true;
}
