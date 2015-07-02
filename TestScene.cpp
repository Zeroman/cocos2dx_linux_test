#include "TestScene.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#include "_debug.h"


USING_NS_CC;

Scene* Test::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();

    // 'layer' is an autorelease object
    auto layer = Test::create();

    // add layer as a child to scene
    scene->addChild(layer);

    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // return the scene
    return scene;
}

void Test::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
    if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Director::getInstance()->end();
    }
}

// on "init" you need to initialize your instance
bool Test::init()
{
    //////////////////////////////
    // 1. super init first
    if(!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // exit with press esc key
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(Test::onKeyReleased, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

