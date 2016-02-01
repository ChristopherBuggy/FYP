#pragma once

#include "cocos2d.h"
#include "Player.h"
#include "GameData.h"
#include <ui\CocosGUI.h>

class leftButton : public cocos2d::Sprite
{
public:
	leftButton();
	static leftButton * create();

	//void initOptions(cocos2d::Vec2 position);

	//void update(float dt);

	void setTTL(int ttl);

	//bool moveLeft = false;
	void addEvents();
	void handleTouchEvent(cocos2d::Touch* touch);
	void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

	bool isTouched() const;

private:
	void initLeft();
};