#include "endGame.h"

USING_NS_CC;

//const double TowerGun::PI = 4.0 * atan(1.0);

endGame::endGame()
{

}

endGame * endGame::create(Vec2 position)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);

	endGame* pSprite = new endGame();
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
		endBody->setAngularVelocity(400);
		
		//Assign the body to sprite
		pSprite->setPhysicsBody(endBody);
	
		//Othe stuff that may or may not be needed.
		pSprite->setAnchorPoint(Point(0.5f, 0.5f));
		pSprite->setScale(.33);


		return pSprite;
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