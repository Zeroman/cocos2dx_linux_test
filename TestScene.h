#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Test : public cocos2d::Layer
{
private:
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(Test);

private:
};

#endif // __HELLOWORLD_SCENE_H__