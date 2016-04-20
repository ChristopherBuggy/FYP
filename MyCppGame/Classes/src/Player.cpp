#include "Player.h"
#include "SimpleAudioEngine.h"

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

		player->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y));

		auto player1Body = PhysicsBody::createBox(player->getContentSize(), PhysicsMaterial(0, 0, 0));
		player1Body->setCollisionBitmask(0x000001);
		player1Body->setRotationEnable(false);
		//player1Body->setCategoryBitmask(0x02);
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
		player->setScale(.8);
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
		auto pBody = p->getPhysicsBody();
		float yVelocity = p->getPhysicsBody()->getVelocity().y;
		p->getPhysicsBody()->setVelocity(Vect(-400, yVelocity));
		//p->getPhysicsBody()->setPositionOffset(Vect(-400, 0));
		//p->setPositionX(pos);
	}
	else
		p->getPhysicsBody()->setVelocity(Vect(400, 0));
}

void Player::pJump(bool pJumped, Player* p) {
	CCLOG("Inside jump method within player Jack class");
	if (pJumped == false)
	{
		p->getPhysicsBody()->applyImpulse(Vect(0, 250));
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Jump.wav", false);
		//p->getPhysicsBody()->applyForce(Vect(0, 40));
	}
	
}

void Player::initPlayer()
{

}

void Player::respawnPoint(Player* p, int i)
{
	if (i == 1)
	{
		p->setPosition(100, 100);
	}
	if (i == 2)
	{
		p->setPosition(500, 400);
	}
	
}

