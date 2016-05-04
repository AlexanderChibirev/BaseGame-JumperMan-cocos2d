#include <iostream>
#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "OptionalScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

GameScene::GameScene()
{

}

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//scene->getPhysicsWorld()->setGravity(Vect(0, -139.8f));
	auto layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return	false;
	
    }
	this->scheduleUpdate();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("bgForTutorial.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3); //форма окна, класс физический, и ширина линии 1 = прозрачный
	edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);//если стокновение ставим тру

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);
	m_baseHero = BaseHero::create();

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [](Touch* touch, Event* event) {
		// your code
		return true; // if you are consuming it
	};

	//button right
	auto rightButtonItem = MenuItemImage::create("heroControl/right.png", "heroControl/rightClicked.png", CC_CALLBACK_1(GameScene::MoveRight, this));
	rightButtonItem->setPosition(Point(120, 50));
	auto rightButtonPlay = Menu::create(rightButtonItem, NULL);
	rightButtonPlay->setPosition(Point::ZERO);

	//button left
	auto leftButtonItem = MenuItemImage::create("heroControl/left.png", "heroControl/leftClicked.png", CC_CALLBACK_1(GameScene::MoveLeft, this));
	leftButtonItem->setPosition(Point(50,  50));
	auto leftButtonPlay = Menu::create(leftButtonItem, NULL);
	leftButtonPlay->setPosition(Point::ZERO);

	//button jump
	auto jumpButtonItem = MenuItemImage::create("heroControl/jump.png", "heroControl/jumpClicked.png", CC_CALLBACK_1(GameScene::MoveUp, this));
	jumpButtonItem->setPosition(Point(visibleSize.width - 50, 60));
	auto jumpButtonPlay = Menu::create(jumpButtonItem, NULL);
	jumpButtonPlay->setPosition(Point::ZERO);
	
	//button pause
	auto pauseButtonItem = MenuItemImage::create("heroControl/pause.png", "heroControl/pauseClicked.png", CC_CALLBACK_1(GameScene::GoToPauseSence, this));
	//pauseButtonItem->setAnchorPoint(Vec2(0.5, -0.5));
	pauseButtonItem->setPosition(30, visibleSize.height - 30);
	auto pauseButtonPlay = Menu::create(pauseButtonItem, NULL);
	pauseButtonPlay->setPosition(Point::ZERO);
	/*if(m_clicked)
	{
		m_baseHero->setPosition(m_baseHero->getPosition().x - 1, m_baseHero->getPosition().y);
	}
*/
	this->addChild(pauseButtonPlay);
	this->addChild(rightButtonPlay);
	this->addChild(leftButtonPlay);
	this->addChild(jumpButtonPlay);

	this->addChild(m_baseHero);

	this->scheduleUpdate();
	return true;
}

void GameScene::MoveLeft(cocos2d::Ref *sender)
{
	m_clicked = true;
}

void GameScene::MoveRight(cocos2d::Ref *sender)
{

}

void GameScene::MoveUp(cocos2d::Ref *sender)
{
	m_baseHero->setPosition(m_baseHero->getPosition().x, m_baseHero->getPosition().y + 100);
}

void GameScene::GoToPauseSence(cocos2d::Ref *sender)
{

}

