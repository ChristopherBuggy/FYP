#include "TowerBase.h"

USING_NS_CC;

TowerBase::TowerBase(GameStates & gameState) : 
m_gameState(gameState),
m_touched(false)
{
	
}

TowerBase * TowerBase::create(Vec2 position, GameStates & gameState)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(ptr->m_textureAtlasPlistFile);		

	TowerBase* pSprite = new TowerBase(gameState);
	if (pSprite->initWithSpriteFrameName(ptr->m_towerBaseFile))
	{
		// This means the sprite will be deleted when it has no references to it.
		pSprite->autorelease();
		// This sets the initial sprite position to the parameter 'position'
		pSprite->initOptions(position);
		// More on this below
		//pSprite->addEvents();

		auto midPlatBody = PhysicsBody::createBox(Size(137.0f, 125.0f), PhysicsMaterial(0, 0, 0));
		midPlatBody->setCollisionBitmask(0x000003);
		midPlatBody->setRotationEnable(false);
		midPlatBody->setContactTestBitmask(true);
		midPlatBody->setDynamic(false);
		//Assign the body to the platform sprite
		pSprite->setPhysicsBody(midPlatBody);

		//Set the anchor point. Probably not needed but I'd rather have it done! 
		pSprite->setAnchorPoint(Point(0.5f, 0.5f));
		pSprite->setScale(.33);

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void TowerBase::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	this->setPosition(position.x + origin.x, position.y + origin.y);
}

void TowerBase::addEvents()
{
	//  Create a "one by one" touch event listener that processes one
	//   touch at a time.
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan 
	//method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	// In simple terms, at the start of a touch event, this callback function is triggered when the user touches the screen.
	// If the touch area is over this sprite, the method returns true to indicate the event was consumed
	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 pos = touch->getLocation();
		cocos2d::Rect rect = this->getBoundingBox();

		if (rect.containsPoint(pos))
		{
			return true; // to indicate that we have consumed it.
		}

		return false; // we did not consume this event, pass through.
	};

	// This callback function is triggered when the user releases their touch on this sprite.
	// The handleTouchEvent method is then called. 
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		handleTouchEvent(touch);
	};

	// This adds an event listener for the above touch events. If this line is not
	//  added, the sprite will not respond to touch events.
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void TowerBase::handleTouchEvent(cocos2d::Touch* touch)
{
	// Change gameState in response to sprite touched
	//Put your movement stuff in here (but in your main obvioudly)
	m_gameState = GameStates::GameInit;
	m_touched = true;
}

bool TowerBase::isTouched() const
{
	return m_touched;
}
