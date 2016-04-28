#include "OptionalScene.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* OptionalScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool OptionalScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	this->scheduleOnce(schedule_selector(OptionalScene::goToMenuScene), 3.0f);
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
	
    return true;
}

void OptionalScene::goToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}