#pragma once

#include "cocos2d.h"


class MenuScene : public cocos2d::Layer
{
public:
	MenuScene();
	static cocos2d::Scene* createScene();
	virtual bool init() override;

	CREATE_FUNC(MenuScene);

private:
	void goToOptionsScene(cocos2d::Ref *sender);
	void goToExitScene(cocos2d::Ref *sender);
	void goToGameScene(cocos2d::Ref *sender);
};