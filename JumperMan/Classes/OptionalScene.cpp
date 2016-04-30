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
	auto playItem = MenuItemImage::create("BackToMenu.png", "BackToMenu.png", CC_CALLBACK_1(OptionalScene::goToMainMenuScene, this));
	playItem->setPosition(Point(80, visibleSize.height - 50 ));
	auto menuPlay = Menu::create(playItem, NULL);
	
	menuPlay->setPosition(Point::ZERO);
	this->addChild(menuPlay);
	return true;
}

void OptionalScene::goToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}