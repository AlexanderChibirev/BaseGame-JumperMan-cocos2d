#include "MenuScene.h"
//#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

MenuScene::MenuScene()
{

}

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}
bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("menu.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto playItem = MenuItemImage::create("Star Button.png", "Start Button Clicked.png", CC_CALLBACK_1(MenuScene::goToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x+10, visibleSize.height / 2 + origin.y+130));

	auto menuPlay = Menu::create(playItem, NULL);

	menuPlay->setPosition(Point::ZERO);
	//
	auto otionalItem = MenuItemImage::create("Options Button.png", "Options Button Clicked.png", CC_CALLBACK_1(MenuScene::goToOptionsScene, this));
	otionalItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y + 50));

	auto menuOtional = Menu::create(otionalItem, NULL);

	menuOtional->setPosition(Point::ZERO);
	//
	auto exitItem = MenuItemImage::create("Exit Button.png", "Exit Button Clicked.png", CC_CALLBACK_1(MenuScene::goToExitScene, this));
	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y));

	auto menuExit = Menu::create(exitItem, NULL);

	menuExit->setPosition(Point::ZERO);

	this->addChild(menuPlay);
	this->addChild(menuOtional);
	this->addChild(menuExit);

	return true;
}

void MenuScene::goToGameScene(cocos2d::Ref *sender)//îáðàáîò÷èê ñîáûòèé
{
	//auto scene = GameScene::createScene();
	//Director::getInstance()->replaceScene(TransitionFlipX::create(1, scene));
}


void MenuScene::goToOptionsScene(cocos2d::Ref *sender) 
{

}
void MenuScene::goToExitScene(cocos2d::Ref *sender)
{

}