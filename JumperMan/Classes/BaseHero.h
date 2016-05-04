#pragma once
#include "SimpleAudioEngine.h"  
#include "cocos2d.h"
#include "Definitions.h"


class BaseHero: public cocos2d::Sprite
{
public:
	BaseHero();
	static BaseHero *create();
	bool init() override;
private:
	cocos2d::Size m_visibleSize;
	cocos2d::Vec2 m_origin;
};
