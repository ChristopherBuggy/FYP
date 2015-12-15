#include "HUD.h"
#include "Player.h"

USING_NS_CC;

HUD * HUD::create()
{
	HUD * left = new HUD();
	if (left && left->initWithFile("GameScreen/rightButtonIdle.png"))
	{
		left->autorelease();
		left->initHUD();
		return left;
	}

	HUD * right = new HUD();
	if (right && right->initWithFile("GameScreen/leftButtonIdle.png"))
	{
		right->autorelease();
		right->initHUD();
		return right;
	}

	CC_SAFE_DELETE(right);
	CC_SAFE_DELETE(left);
	return NULL;
}

void HUD::initHUD()
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