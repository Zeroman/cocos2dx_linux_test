/// @file TestSchedule.cpp
/// @brief 
/// @author Zeroman Yang <51feel@gmail.com>
/// 0.01
/// @date 2015-07-12


#include "TestItem.h"

static void *_target = (void *)0x13020;

static void update(float dt)
{
    log("---------%f", dt);
    auto p = Director::getInstance()->getScheduler();
    p->unscheduleAllForTarget(_target);
}

static bool testSchedule1()
{
    const std::string key = "test";
    auto p = Director::getInstance()->getScheduler();
    ccSchedulerFunc func = std::bind(&update, std::placeholders::_1);
    p->schedule(func, _target, 1.0f, CC_REPEAT_FOREVER, 3.0f, false, key);
    return true;
}

TTestItem * addSheduleTest()
{
    TTestItem *pItem = new TTestItem();
    pItem->addTest("Schedule test 1", std::bind(&testSchedule1));
    pItem->addBackItem();
    return pItem;
}

