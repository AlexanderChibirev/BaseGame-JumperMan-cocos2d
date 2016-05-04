#pragma once
#include "BaseHero.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "cocos2d.h"
#include "Definitions.h"

class GameScene : public cocos2d::Layer
{
public:
	GameScene();
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(GameScene);
private:
	BaseHero *m_baseHero;
	void MoveLeft(cocos2d::Ref *sender);
	void GoToPauseSence(cocos2d::Ref *sender);
	void MoveRight(cocos2d::Ref *sender);
	void MoveUp(cocos2d::Ref *sender);
	bool m_clicked;
};