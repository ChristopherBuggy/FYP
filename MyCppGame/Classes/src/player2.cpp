#include "Player2.h"

USING_NS_CC;

Player2 * Player2::create()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Player2 * player2 = new Player2();
	if (player2 && player2->initWithFile("GameScreen/player2.png"))
	{
		player2->autorelease();
		player2->initPlayer();

		player2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		auto player2Body = PhysicsBody::createBox(player2->getContentSize(), PhysicsMaterial(0, 1, 0));
		player2Body->setCollisionBitmask(0x000002);
		player2Body->setRotationEnable(false);
		player2Body->setContactTestBitmask(true);
		player2Body->setDynamic(true);

		//Assign the body to the sprite.
		player2->setPhysicsBody(player2Body);

		player2->setPosition(Vec2(origin.x + visibleSize.width / 4,
			origin.y + visibleSize.height / 4));
		player2->setAnchorPoint(Point(0.5f, 0.5f));
		player2->setScale(.33);

		return player2;
	}


	CC_SAFE_DELETE(player2);
	return NULL;
}

void Player2::initPlayer()
{

}

void Player2::Movement() {


}