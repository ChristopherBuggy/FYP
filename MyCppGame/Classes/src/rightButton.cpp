#include "rightButton.h"
#include "Player.h"

USING_NS_CC;

rightButton * rightButton::create()
{
	rightButton * right = new rightButton();
	if (right && right->initWithFile("GameScreen/rightButtonIdle.png"))
	{
		right->autorelease();
		right->initRight();
		return right;
	}


	CC_SAFE_DELETE(right);
	return NULL;
}

void rightButton::initRight()
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