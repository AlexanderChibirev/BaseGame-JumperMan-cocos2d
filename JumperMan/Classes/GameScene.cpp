#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "GameScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	////
	//this->scheduleOnce(schedule_selector(GameScene::goToMenuScene), 3.0f);
	//auto rootNode = CSLoader::createNode("MainScene.csb");
	//addChild(rootNode);
	////
    return true;
}

void GameScene::goToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}