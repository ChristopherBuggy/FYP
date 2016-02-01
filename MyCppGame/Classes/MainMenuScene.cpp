#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = MainMenu::create();

	scene->addChild(layer);

	return scene;
}

void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	/*auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.50, 0.50));
	label->setPosition(Vec2(350, 300));
	this->addChild(label, 1);*/

	return true;
}

