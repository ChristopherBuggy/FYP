#pragma once

#define COCOS2D_DEBUG 1
#include "cocos2d.h"
#include "LevelLoader.h"

class  AppDelegate : private cocos2d::Application
{
private:
	std::shared_ptr<GameData> m_ptr;

public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual bool applicationDidFinishLaunching();
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
};