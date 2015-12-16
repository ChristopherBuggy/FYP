#include "leftButton.h"


USING_NS_CC;

leftButton * leftButton::create()
{
	leftButton * left = new leftButton();
	if (left && left->initWithFile("GameScreen/leftButtonIdle.png"))
	{
		left->autorelease();
		left->initLeft();

		left->addEvents();
		return left;
	}

	CC_SAFE_DELETE(left);
	return NULL;
}

void leftButton::initLeft()
{
	

	/*Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	//Set Pause button position
	leftItem->setPosition(Point(leftItem->getContentSize().width -
		(leftItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - leftItem->getContentSize().height +
		(leftItem->getContentSize().width / 4) + origin.y));
		*/
}

void leftButton::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{

}

void leftButton::addEvents()
{
	//auto listener = cocos2d::EventListenerTouchAllAtOnce::create();
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
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
			return true; //to indicate we consumed it and were touched.
		}

		return false; //We did not consume it and hense were not touched!

	};

	// This callback function is triggered when the user releases their touch on this sprite.
	// The handleTouchEvent method is then called. 
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		int x = 0;
		handleTouchEvent(touch);
	};

	//This call back is called while the user is holding their finger down on the sprite (well, that's the idea)
	//With out this line, the sprite will do nothing! Nooooothing! 
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);

}

void leftButton::handleTouchEvent(cocos2d::Touch* touch)
{
	CCLOG("Entered Button Presses...");
	//moveLeft = true;
	//Player::Movement(moveLeft)
	return;
}