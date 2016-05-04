#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "GameScene.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
	
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//this->scheduleOnce(schedule_selector(MainScene::goToHistiry1Scene), 2.0f);
	this->scheduleOnce(schedule_selector(MainScene::goToMainMenuScene), 2.0f);
    auto rootNode = CSLoader::createNode("history1.csb");
    addChild(rootNode);
	
    return true;
}
//void MainScene::onEnter()
//{
////	CCSpriteFrameCache* frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
////	frameCache->addSpriteFramesWithFile("GO.plist");
////
////	CCSpriteBatchNode* spritesheet = CCSpriteBatchNode::create("GO.png");
////	this->addChild(spritesheet);
////	
//////	CCArray* gooberFrames = new CCArray;
////	 cocos2d::Vector<cocos2d::SpriteFrame *> _bullets;
////	CCString* filename = CCString::createWithFormat("Hero1.png");
////	CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
////	//gooberFrames->addObject(frame);
////	_bullets.pushBack(frame);
////
////
////	CCAnimation* runAnim = CCAnimation::createWithSpriteFrames(_bullets, 0.1);
////	CCSprite* goober = CCSprite::createWithSpriteFrameName("GO.png");
////
////	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
////	goober->setPosition(ccp(winsize.width*0.5, winsize.height*0.5));
////
////	CCAction* action = CCRepeatForever::create(CCAnimate::create(runAnim));
////
////	goober->runAction(action);
////	spritesheet->addChild(goober);
//
//}
void MainScene::goToMainMenuScene(float dt)
{
	//auto scene = MenuScene::createScene();
	//Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
}

void MainScene::goToHistiry1Scene(float dt)
{
	auto rootNode = CSLoader::createNode("history2.csb");
	addChild(rootNode);
	this->scheduleOnce(schedule_selector(MainScene::goToHistiry2Scene), 2.0f);
}

void MainScene::goToHistiry2Scene(float dt)
{
	auto rootNode = CSLoader::createNode("history3.csb");
	addChild(rootNode);
	this->scheduleOnce(schedule_selector(MainScene::goToHistiry3Scene), 3.0f);
}

void MainScene::goToHistiry3Scene(float dt)
{
	auto rootNode = CSLoader::createNode("history4.csb");
	addChild(rootNode);
	this->scheduleOnce(schedule_selector(MainScene::goToHistiry4Scene), 2.0f);
}

void MainScene::goToHistiry4Scene(float dt)
{
	auto rootNode = CSLoader::createNode("history5.csb");
	addChild(rootNode);
	this->scheduleOnce(schedule_selector(MainScene::goToMainMenuScene), 3.0f);
}
