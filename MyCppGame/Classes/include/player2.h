#pragma once

#include "cocos2d.h"


class Player2 : public cocos2d::Sprite {

public:
	static Player2 * create(void);
	void p2Movement(Player2* p, bool dir);
	void p2Jump(bool p2Jumped, Player2* p);

private:
	void initPlayer();
};