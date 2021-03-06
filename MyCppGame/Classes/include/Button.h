#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"


class Button : public cocos2d::Sprite
{
private:

public:
	Button();

	static Button * create(cocos2d::Vec2 position, int i);

	void changeSprite(Button* b);
	void initOptions(cocos2d::Vec2 position);

	void update(float dt);

};