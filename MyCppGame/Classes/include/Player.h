#pragma once

#include "cocos2d.h"


class Player : public cocos2d::Sprite {

public:
	static Player * create(void);
	void pMovement(Player* p, bool dir);
	void pJump(bool pJumped, Player* p);
	void respawnPoint(Player* p, int i);

private:
	void initPlayer();
};