#include "GameScene.h"
#include "OptionalScene.h"
#define ACTION_PLAY 1
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
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("bgForTutorial.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//this->addChild(backgroundSprite);
	cocos2d::CCTMXTiledMap *m_tileMap = CCTMXTiledMap::create("tmx/layer_1.tmx");

	CCTMXLayer *m_collisionLayer = m_tileMap->layerNamed("tiles");
	this->addChild(m_tileMap);

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
	ui::Button* rightButtonPlay = ui::Button::create("heroControl/right.png", "heroControl/rightClicked.png");
	rightButtonPlay->setPosition(Point(120, 50));
	rightButtonPlay->addTouchEventListener(CC_CALLBACK_2(GameScene::MoveRight, this));
	
	//button left
	ui::Button* leftButtonPlay = ui::Button::create("heroControl/left.png", "heroControl/leftClicked.png");
	leftButtonPlay->setPosition(Point(50, 50));
	leftButtonPlay->addTouchEventListener(CC_CALLBACK_2(GameScene::MoveLeft, this));

	//button jump
	ui::Button* jumpButtonPlay = ui::Button::create("heroControl/jump.png", "heroControl/jumpClicked.png");
	jumpButtonPlay->setPosition(Point(visibleSize.width - 50, 60));
	jumpButtonPlay->addTouchEventListener(CC_CALLBACK_2(GameScene::MoveUp, this));

	//button pause
	auto pauseButtonItem = MenuItemImage::create("heroControl/pause.png", "heroControl/pauseClicked.png", CC_CALLBACK_1(GameScene::GoToPauseSence, this));
	pauseButtonItem->setPosition(30, visibleSize.height - 30);
	auto pauseButtonPlay = Menu::create(pauseButtonItem, NULL);
	pauseButtonPlay->setPosition(Point::ZERO);
	
	//this->addChild(pauseButtonPlay);
	this->addChild(rightButtonPlay);
	this->addChild(leftButtonPlay);
	this->addChild(jumpButtonPlay);

	this->addChild(m_baseHero);

	this->scheduleUpdate();



	return true;
}

void GameScene::MoveLeft(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType)
	{
		m_clickedLeft = true;
	}
	else
	{
		m_clickedLeft = false;
	}
	return;
}

void GameScene::MoveRight(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType)
	{
		m_clickedRight= true;
	}
	else
	{
		m_clickedRight = false;
	}
	return;
}

void GameScene::MoveUp(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType)
	{
		m_clickedJump = true;
	}
	else
	{
		m_clickedJump = false;
	}
	return;
}

void GameScene::update(float dt)
{
	if (m_clickedJump)
	{
		m_baseHero->setPosition(m_baseHero->getPosition().x, m_baseHero->getPosition().y + 2);
	}
	if(m_clickedLeft)
	{
		m_baseHero->setPosition(m_baseHero->getPosition().x - 2, m_baseHero->getPosition().y );
	}
	if (m_clickedRight) 
	{
		m_baseHero->setPosition(m_baseHero->getPosition().x + 2, m_baseHero->getPosition().y );
	}
	//m_baseHero->setPosition(m_baseHero->getPosition().x, m_baseHero->getPosition().y - 2);
}

void GameScene::GoToPauseSence(cocos2d::Ref *sender)
{

}

