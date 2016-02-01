#include "GameOverScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameScreen::create();

	scene->addChild(layer);

	return scene;
}

void GameScreen::activatePauseScene(Ref *pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScreen::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
}

bool GameScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

