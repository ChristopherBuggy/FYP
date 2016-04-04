#include "Player.h"

USING_NS_CC;

Player * Player::create()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Player * player = new Player();
	if (player && player->initWithFile("GameScreen/player.png"))
	{
		player->autorelease();
		player->initPlayer();
		//cocos2d::Size size(60, 120);
		player->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y));
		player->setTag(10);

		auto player1Body = PhysicsBody::createBox(player->getContentSize(), PhysicsMaterial(0, 1, 10));
		player1Body->setRotationEnable(false);
		player1Body->setCollisionBitmask(0x000001);
		player1Body->setContactTestBitmask(true);
		player1Body->setTag(10);

		player1Body->setDynamic(true);
		//player1Body->setVelocity(Vect(100, 247));
		player1Body->setLinearDamping(0);
		//player1Body->applyForce(Vect(100, 245));

		//Assign the body to sprite
		player->setPhysicsBody(player1Body);

		player->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 4));
		player->setAnchorPoint(Point(0.5f, 0.5f));
		player->setScale(.33);
		//player->pMovement(player);
		
		//this->addChild(sprite);
		
		return player;
	}
	
	CC_SAFE_DELETE(player);
	return NULL;
}

void Player::pMovement(Player* p, bool dir) {
	if (dir == true) {
		//int pos = p->getPositionX() - 10;
		p->getPhysicsBody()->setVelocity(Vect(-400, 0));
		//p->getPhysicsBody()->setPositionOffset(Vect(-400, 0));
		//p->setPositionX(pos);
	}
	else
		p->getPhysicsBody()->setVelocity(Vect(400, 0));
}

void Player::pJump(Player* p) {
	CCLOG("Inside jump method within player Jack class");
	p->getPhysicsBody()->applyImpulse(Vect(0, 200));
	//p->getPhysicsBody()->applyForce(Vect(0, 40));
}

void Player::initPlayer()
{

}

void Player::respawnPoint(Player* p)
{
	p->setPosition(100, 100);
}

