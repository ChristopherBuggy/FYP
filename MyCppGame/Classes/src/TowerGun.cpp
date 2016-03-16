#include "TowerGun.h"

USING_NS_CC;

//const double TowerGun::PI = 4.0 * atan(1.0);

TowerGun::TowerGun()
{

}

TowerGun * TowerGun::create(Vec2 position)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);

	TowerGun* pSprite = new TowerGun();
	if (pSprite->initWithSpriteFrameName(ptr->m_towerGunFile))
	{
		pSprite->autorelease();

		//pSprite->initOptions(position);
		pSprite->setPosition(500, (position.y + origin.y + pSprite->getContentSize().height / 4) + 20);
		pSprite->setTag(21);

		//Body for the trap!
		auto trapBody = PhysicsBody::createCircle(pSprite->getContentSize().width / 2, PhysicsMaterial(100, 0, 0));
		trapBody->setRotationEnable(true);
		trapBody->setGravityEnable(false);
		trapBody->setCollisionBitmask(0x000004);
		trapBody->setContactTestBitmask(true);
		//trapBody->setDynamic(false);
		trapBody->setAngularVelocity(400);
		trapBody->setTag(20);
		//Assign the body to sprite
		pSprite->setPhysicsBody(trapBody);
				

		//Othe stuff that may or may not be needed.
		pSprite->setAnchorPoint(Point(0.5f, 0.5f));
		pSprite->setScale(.33);
		

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void TowerGun::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	// Set the anchor point lower on the y-axis for the tower gun, so rotations look better.
}



void TowerGun::update(float dt) 
{
		
}

void TowerGun::removeTrap(TowerGun* trapBody)
{
	trapBody->removeFromParentAndCleanup(true);
}