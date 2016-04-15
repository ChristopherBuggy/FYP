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
	//This is a fancy transition. 
	//Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
	Director::getInstance()->replaceScene(scene);
}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto backGroundSprite = Sprite::create("MainMenuScreen/bg.png");
	backGroundSprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	backGroundSprite->setScale(3);
	this->addChild(backGroundSprite);

	auto menuTitle =
		MenuItemImage::create("MainMenuScreen/Game_Title.png",
			"MainMenuScreen/Game_Title.png");
	menuTitle->setScale(2);

	auto playItem =
		MenuItemImage::create("MainMenuScreen/play.png",
			"MainMenuScreen/playClick.png",
			CC_CALLBACK_1(MainMenu::activateGameScene, this));
	auto menu = Menu::create(menuTitle, playItem, NULL);

	// Returns visible size of OpenGL window in points.
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

	return true;
}