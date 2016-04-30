#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
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

	this->scheduleOnce(schedule_selector(MainScene::goToHistiry1Scene), 2.0f);
    auto rootNode = CSLoader::createNode("history1.csb");
    addChild(rootNode);
	
    return true;
}

void MainScene::goToMainMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
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
