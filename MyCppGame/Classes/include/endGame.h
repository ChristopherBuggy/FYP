#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"


class endGame : public cocos2d::Sprite
{
private:

public:
	endGame();

	static endGame * create(cocos2d::Vec2 position);

	void initOptions(cocos2d::Vec2 position);

	void update(float dt);

};
