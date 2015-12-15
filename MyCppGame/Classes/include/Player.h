#pragma once

#include "cocos2d.h"


class Player : public cocos2d::Sprite {

public:
	static Player * create(void);
	void Movement();

private:
	void initPlayer();
};