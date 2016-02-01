#include "PauseScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseMenu::create();

	scene->addChild(layer);

	return scene;
}

bool PauseMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void PauseMenu::resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void PauseMenu::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseMenu::retry(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}