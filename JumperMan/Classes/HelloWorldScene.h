#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	//void onEnter();
    CREATE_FUNC(MainScene);
private:
	void goToMainMenuScene(float dt);
	void goToHistiry1Scene(float dt);
	void goToHistiry2Scene(float dt);
	void goToHistiry3Scene(float dt);
	void goToHistiry4Scene(float dt);

};

#endif // __HELLOWORLD_SCENE_H__
