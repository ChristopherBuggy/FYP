#pragma once

#include "cocos2d.h"


class Player2 : public cocos2d::Sprite {

public:
	static Player2 * create(void);
	void Movement();

private:
	void initPlayer();
};