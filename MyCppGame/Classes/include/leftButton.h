#pragma once

#include "cocos2d.h"

class leftButton : public cocos2d::Sprite
{
public:

	static leftButton * create();

	void addEvents();
	void handleTouchEvent(cocos2d::Touch* touch);
	void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

	bool isTouched() const;

private:
	void initLeft();
};