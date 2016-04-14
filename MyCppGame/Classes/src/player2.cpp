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

		auto player2Body = PhysicsBody::createBox(player2->getContentSize(), PhysicsMaterial(0, 0, 0));
		player2Body->setCollisionBitmask(0x000002);
		player2Body->setRotationEnable(false);
		//player1Body->setCategoryBitmask(0x02);
		player2Body->setContactTestBitmask(true);
		player2Body->setTag(11);

		player2Body->setDynamic(true);

		//player2Body->setLinearDamping(0);
		
		
		//Assign the body to sprite
		player2->setPhysicsBody(player2Body);

		player2->setPosition(Vec2(origin.x + visibleSize.width / 4,
			origin.y + visibleSize.height / 4));
		player2->setAnchorPoint(Point(0.5f, 0.5f));
		player2->setScale(.8);

		return player2;
	}


	CC_SAFE_DELETE(player2);
	return NULL;
}

void Player2::initPlayer()
{

}

void Player2::p2Movement(Player2* p, bool dir) {
	if (dir == true) {
		p->getPhysicsBody()->setVelocity(Vect(-300, 0));
	}
	else
		p->getPhysicsBody()->setVelocity(Vect(300, 0));
}

void Player2::p2Jump(bool p2Jumped, Player2* p) {
	CCLOG("Inside jump method within player class");
	if (p2Jumped == false)
	{
		p->getPhysicsBody()->applyImpulse(Vect(0, 260));
	}
	
}

void Player2::respawnPoint(Player2* p)
{
	p->setPosition(200, 100);
}