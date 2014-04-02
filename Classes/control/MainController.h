#ifndef __MAINCONTROLLER_SCENE_H__
#define __MAINCONTROLLER_SCENE_H__

#include "cocos2d.h"

class MainController : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	// scale out callback
	void menuScaleOutCallback(cocos2d::Ref* pSender);

	// scale in callback
	void menuScaleInCallback(cocos2d::Ref* pSender);

	// debug mode
	void menuDebugCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainController);
};

#endif // __MAINCONTROLLER_SCENE_H__
