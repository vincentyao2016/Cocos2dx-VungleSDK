#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "VunglePubAd.h"
#endif

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    cocos2d::ui::Button* showAdBtn;
    cocos2d::ui::Button* showAdWithOptionsBtn;
    cocos2d::ui::Button* showIncentivizedAdBtn;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
