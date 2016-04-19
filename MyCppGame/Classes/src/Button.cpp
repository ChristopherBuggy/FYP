#include "Button.h"

USING_NS_CC;

//const double TowerGun::PI = 4.0 * atan(1.0);

Button::Button()
{

}

Button * Button::create(Vec2 position, int i)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);

	Button* pButton = new Button();
	if (pButton->initWithSpriteFrameName(ptr->m_buttonUnpressed) && i == 1)
	{
		pButton->autorelease();
		//The thing below. Use that to change sprite when pressed!
		//pButton->setSpriteFrame(ptr->m_buttonPressed);
		//pSprite->initOptions(position);
		pButton->setPosition(525, 250);
		pButton->setTag(20);

		//Body for the trap!
		auto buttonBody = PhysicsBody::createBox(pButton->getContentSize(), PhysicsMaterial(100, 0, 0));
		buttonBody->setGravityEnable(false);
		buttonBody->setDynamic(false);
		buttonBody->setCollisionBitmask(0x000005);
		buttonBody->setContactTestBitmask(true);
		buttonBody->setTag(20);

		//Assign the body to sprite
		pButton->setPhysicsBody(buttonBody);

		//Othe stuff that may or may not be needed.
		pButton->setAnchorPoint(Point(0.5f, 0.5f));
		pButton->setScale(1.5);


		return pButton;
	}
	if (pButton->initWithSpriteFrameName(ptr->m_buttonUnpressed) && i == 2)
	{
		pButton->autorelease();
		//The thing below. Use that to change sprite when pressed!
		//pButton->setSpriteFrame(ptr->m_buttonPressed);
		//pSprite->initOptions(position);
		pButton->setPosition(200, 200);
		pButton->setTag(20);

		//Body for the trap!
		auto buttonBody = PhysicsBody::createBox(pButton->getContentSize(), PhysicsMaterial(100, 0, 0));
		buttonBody->setGravityEnable(false);
		buttonBody->setDynamic(false);
		buttonBody->setCollisionBitmask(0x000005);
		buttonBody->setContactTestBitmask(true);
		buttonBody->setTag(20);

		//Assign the body to sprite
		pButton->setPhysicsBody(buttonBody);

		//Othe stuff that may or may not be needed.
		pButton->setAnchorPoint(Point(0.5f, 0.5f));
		pButton->setScale(1.5);


		return pButton;
	}

	CC_SAFE_DELETE(pButton);
	return NULL;
}

void Button::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Set the anchor point lower on the y-axis for the tower gun, so rotations look better.
}
void Button::changeSprite(Button* b)
{
	//b->setSpriteFrame(ptr->m_buttonPressed);
}

void Button::update(float dt)
{

}