#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"


class TowerGun : public cocos2d::Sprite
{
private:

public:
	TowerGun();

	static TowerGun * create(cocos2d::Vec2 position);

	void initOptions(cocos2d::Vec2 position);

	void update(float dt);

	void removeTrap(TowerGun* trapBody);
};