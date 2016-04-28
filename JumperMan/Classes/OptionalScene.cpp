#include "OptionalScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* OptionalScene::createScene()
{
    auto scene = Scene::create();
    auto layer = OptionalScene::create();
    scene->addChild(layer);
    return scene;
}

bool OptionalScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto backgroundSprite = Sprite::create("bgOption.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	//auto myLabel = Label::createWithSystemFont("My Label Text", "Arial", 59);
	//auto closeItem = MenuItemImage::create("BackToMenu.png", "BackToMenu.png", CC_CALLBACK_1(OptionalScene::goToMainMenuScene(1), this));
	/*auto closeItem = MenuItemImage::create("BackToMenu.png", "BackToMenu.png", CC_CALLBACK_1(OptionalScene::goToMainMenuScene, this));
	auto menu = Menu::create(closeItem, NULL);
	this->addChild(menu, 1);
	*///auto menuItem = MenuItemImage::create("BackToMenu.png", "BackToMenu.png", CC_CALLBACK_1(OptionalScene::gooooo, this));
	//menuItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y));
	//auto menuBack = Menu::create(menuItem, NULL);
	//menuBack->setPosition(Point::ZERO);
	//this->addChild(menuBack);
	auto playItem = MenuItemImage::create("Star Button.png", "Start Button Clicked.png", CC_CALLBACK_1(OptionalScene::goToMainMenuScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y + 130));

	auto menuPlay = Menu::create(playItem, NULL);

	menuPlay->setPosition(Point::ZERO);
	//
//	auto otionalItem = MenuItemImage::create("Options Button.png", "Options Button Clicked.png", CC_CALLBACK_1(OptionalScene::goToOptionsScene, this));
//	otionalItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y + 50));

// 	auto menuOtional = Menu::create(otionalItem, NULL);

//menuOtional->setPosition(Point::ZERO);
	//
//	auto exitItem = MenuItemImage::create("Exit Button.png", "Exit Button Clicked.png", CC_CALLBACK_1(OptionalScene::goToExitScene, this));
//	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x + 10, visibleSize.height / 2 + origin.y));

//	auto menuExit = Menu::create(exitItem, NULL);

	//menuExit->setPosition(Point::ZERO);

	this->addChild(menuPlay);
//	this->addChild(menuOtional);
	//this->addChild(menuExit);



	return true;
}

void OptionalScene::goToMainMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}