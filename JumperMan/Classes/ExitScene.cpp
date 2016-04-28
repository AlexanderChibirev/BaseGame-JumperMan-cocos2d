#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "ExitScene.h"
USING_NS_CC;

using namespace cocostudio::timeline;


Scene* ExitScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ExitScene::create();
    scene->addChild(layer);
    return scene;
}

bool ExitScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	/*this->scheduleOnce(schedule_selector(ExitScene::goToMenuScene), 3.0f);
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
	*/
    return true;
}

void ExitScene::goToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}