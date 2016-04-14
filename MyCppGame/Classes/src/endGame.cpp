#include "endGame.h"

USING_NS_CC;

//const double TowerGun::PI = 4.0 * atan(1.0);

endGame::endGame()
{

}

endGame * endGame::create(Vec2 position, int selection)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);

	endGame* pSprite = new endGame();

	if (selection == 1)
	{
		if (pSprite->initWithSpriteFrameName(ptr->m_endGameArea))
		{
			pSprite->autorelease();

			//pSprite->initOptions(position);
			pSprite->setPosition(100, 398);
			//Body for the trap!
			auto endBody = PhysicsBody::createBox(pSprite->getContentSize(), PhysicsMaterial(0, 0, 0));

			endBody->setCollisionBitmask(0x000006);
			//endBody->setCategoryBitmask(0x02); //I want to keep this in the same catagory as the players s they can pass through 
			//but I can still detect collision with the bitmask.
			endBody->setContactTestBitmask(true);
			endBody->setDynamic(false);

			//Assign the body to sprite
			pSprite->setPhysicsBody(endBody);

			//Othe stuff that may or may not be needed.
			pSprite->setAnchorPoint(Point(0.5f, 0.5f));
			//pSprite->setScale(.33);


			return pSprite;
		}
	}
	else if (selection == 2)
	{
		if (pSprite->initWithFile("GameScreen/playerOneEnd.png"))
		{
			pSprite->autorelease();

			//pSprite->initOptions(position);
			pSprite->setPosition(50, 420);
			//Body for the endplat jack!
			auto endJackBody = PhysicsBody::createBox(pSprite->getContentSize(), PhysicsMaterial(0, 0, 0));

			//endBody->setCollisionBitmask(0x000006);
			//endBody->setCategoryBitmask(0x02); //I want to keep this in the same catagory as the players s they can pass through 
			//but I can still detect collision with the bitmask.
			endJackBody->setContactTestBitmask(true);
			endJackBody->setDynamic(false);
			endJackBody->setTag(7);
			//Assign the body to sprite
			pSprite->setPhysicsBody(endJackBody);

			//Othe stuff that may or may not be needed.
			pSprite->setAnchorPoint(Point(0.5f, 0.5f));
			pSprite->setScale(.8);
			//pSprite->setScale(.33);


			return pSprite;
		}
	}
	else if (selection == 3)
	{
		if (pSprite->initWithFile("GameScreen/playerTwoEnd.png"))
		{
			pSprite->autorelease();
			//pSprite->initPlayer();
			//pSprite->initOptions(position);
			pSprite->setPosition(100, 420);
			//Body for the endplat jack!
			auto endJillBody = PhysicsBody::createBox(pSprite->getContentSize(), PhysicsMaterial(0, 0, 0));

			//endBody->setCollisionBitmask(0x000006);
			//endBody->setCategoryBitmask(0x02); //I want to keep this in the same catagory as the players s they can pass through 
			//but I can still detect collision with the bitmask.
			endJillBody->setContactTestBitmask(true);
			endJillBody->setDynamic(false);
			endJillBody->setTag(8);
			//Assign the body to sprite
			pSprite->setPhysicsBody(endJillBody);

			//Othe stuff that may or may not be needed.
			pSprite->setAnchorPoint(Point(0.5f, 0.5f));
			pSprite->setScale(.8);
			//pSprite->setScale(.33);

			return pSprite;
		}
	}
	
	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void endGame::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	// Set the anchor point lower on the y-axis for the tower gun, so rotations look better.
}



void endGame::update(float dt)
{

}