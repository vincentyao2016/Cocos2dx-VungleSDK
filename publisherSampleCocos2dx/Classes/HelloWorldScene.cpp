#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    auto bg = cocos2d::LayerColor::create(Color4B(39, 143, 209, 255));
    this->addChild(bg);
    
    showAdBtn = cocos2d::ui::Button::create();
    showAdBtn->setTitleText("showAd");
    showAdBtn->setTitleFontSize(20);
    showAdBtn->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/2 + origin.y));
    showAdBtn->loadTextures("normal_image.png", "selected_image.png", "disabled_image.png");
    showAdBtn->setScale9Enabled(true);
    showAdBtn->setContentSize(cocos2d::Size(200.0f, showAdBtn->getTitleRenderer()->getContentSize().height*2.0f));
    showAdBtn->addClickEventListener([&](Ref* sender){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        cocos2d::JniMethodInfo methodInfo;
        if (! cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/VungleAdPub", "playAd", "()Z")) {
            return;
        }
        jboolean isAdPlayable =methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        
        bool b=(bool)(isAdPlayable == JNI_TRUE);
        if(!b){
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
        
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if(VunglePubAd::isAdPlayable()){
            VunglePubAd::showAd();
        }
        else{
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
#endif
        
    });
    this->addChild(showAdBtn,0);
    
    showAdWithOptionsBtn = cocos2d::ui::Button::create();
    showAdWithOptionsBtn->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/2 + origin.y+80));
    showAdWithOptionsBtn->setTitleText("showAdWithOptions");
    showAdWithOptionsBtn->setTitleFontSize(20);
    showAdWithOptionsBtn->loadTextures("normal_image.png", "selected_image.png", "disabled_image.png");
    showAdWithOptionsBtn->setScale9Enabled(true);
    showAdWithOptionsBtn->setContentSize(cocos2d::Size(200.0f, showAdWithOptionsBtn->getTitleRenderer()->getContentSize().height*2.0f));
    showAdWithOptionsBtn->addClickEventListener([&](Ref* sender){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        cocos2d::JniMethodInfo methodInfo;
        if (!cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/VungleAdPub", "showAdWithOptions", "()Z")) {
            return;
        }
        jboolean isAdPlayable =methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        
        bool b=(bool)(isAdPlayable == JNI_TRUE);
        if(!b){
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if(VunglePubAd::isAdPlayable()){
            VunglePubAd::showAdWithOptions();
        }
        else{
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
#endif
        
    });
    this->addChild(showAdWithOptionsBtn,0);
    
    showIncentivizedAdBtn = cocos2d::ui::Button::create();
    showIncentivizedAdBtn->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/2 + origin.y-80));
    showIncentivizedAdBtn->setTitleText("showIncentivizedAd");
    showIncentivizedAdBtn->setTitleFontSize(20);
    showIncentivizedAdBtn->loadTextures("normal_image.png", "selected_image.png", "disabled_image.png");
    showIncentivizedAdBtn->setScale9Enabled(true);
    showIncentivizedAdBtn->setContentSize(cocos2d::Size(200.0f, showIncentivizedAdBtn->getTitleRenderer()->getContentSize().height*2.0f));
    showIncentivizedAdBtn->addClickEventListener([&](Ref* sender){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        cocos2d::JniMethodInfo methodInfo;
        if (! cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/VungleAdPub", "showIncentivizedAd", "()Z")) {
            return;
        }
        jboolean isAdPlayable =methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        
        bool b=(bool)(isAdPlayable == JNI_TRUE);
        if(!b){
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
        
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        if(VunglePubAd::isAdPlayable()){
            VunglePubAd::showIncentivizedAd();
        }
        else{
            MessageBox("isAdPlayable", "No Cached ad to play");
        }
#endif
    });
    this->addChild(showIncentivizedAdBtn,0);
    
    auto vungleLogo = Sprite::create("VungleLogo.png");
//    vungleLogo->setScale(2);
    vungleLogo->setPosition(Vec2(origin.x + visibleSize.width/4,
                                 origin.y + visibleSize.height/2 + vungleLogo->getContentSize().height/2));
    this->addChild(vungleLogo, 0);
    return true;
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"
{
    JNIEXPORT
    void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdStartCppFunction(JNIEnv* env, jobject thiz);
    void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdEndCppFunction(JNIEnv* env, jobject thiz);
    void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdPlayableChangedCppFunction(JNIEnv* env, jobject thiz,jboolean isAdPlayable);
    void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdUnavailableCppFunction(JNIEnv* env, jobject thiz);
};
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdStartCppFunction(JNIEnv* env, jobject thiz)
{
    // Called before playing an ad
}
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdEndCppFunction(JNIEnv* env, jobject thiz)
{
    // Called when the user leaves the ad and control is returned to your application
    // if wasSuccessfulView is true, the user watched the ad and should be rewarded
    // (if this was a rewarded ad).
    // if wasCallToActionClicked is true, the user clicked the call to action
    // button in the ad.
}
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdPlayableChangedCppFunction(JNIEnv* env, jobject thiz,jboolean isAdPlayable)
{
    // Called when the playability state changes. if isAdPlayable is true, you can now
    // play an ad.
    // If false, you cannot yet play an ad.
}
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_onAdUnavailableCppFunction(JNIEnv* env, jobject thiz)
{
    // Called when VunglePub.playAd() was called, but no ad was available to play
}
#endif


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
