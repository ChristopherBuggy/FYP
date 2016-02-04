#include "Button.h"

USING_NS_CC;

//const double TowerGun::PI = 4.0 * atan(1.0);

Button::Button()
{

}

Button * Button::create(Vec2 position)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);

	Button* pSprite = new Button();
	if (pSprite->initWithSpriteFrameName(ptr->m_buttonUnpressed))
	{
		pSprite->autorelease();
		//The thing below. Use that to change sprite when pressed!
		//pSprite->setSpriteFrame(ptr->m_buttonPressed);
		//pSprite->initOptions(position);
		pSprite->setPosition(100, 100);
		//Body for the trap!
		auto buttonBody = PhysicsBody::createBox(pSprite->getContentSize(), PhysicsMaterial(100, 0, 0));
		//buttonBody->setRotationEnable(false);
		buttonBody->setGravityEnable(false);
		buttonBody->setDynamic(false);
		buttonBody->setCollisionBitmask(0x000005);
		buttonBody->setContactTestBitmask(true);
		//trapBody->setDynamic(false);
		buttonBody->setAngularVelocity(400);

		//Assign the body to sprite
		pSprite->setPhysicsBody(buttonBody);

		//Othe stuff that may or may not be needed.
		pSprite->setAnchorPoint(Point(0.5f, 0.5f));
		pSprite->setScale(1);


		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void Button::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Set the anchor point lower on the y-axis for the tower gun, so rotations look better.
}



void Button::update(float dt)
{

}