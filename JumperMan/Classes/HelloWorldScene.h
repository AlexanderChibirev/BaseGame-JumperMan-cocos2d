#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
private:
	void goToMainMenuScene(float dt);
};

#endif // __HELLOWORLD_SCENE_H__