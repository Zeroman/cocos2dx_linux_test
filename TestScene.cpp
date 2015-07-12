
#include "TestScene.h"
#include "TestItem.h"
#include "_debug.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

using namespace cocos2d;
using namespace cocos2d::ui;

extern TTestItem * addSheduleTest();

static TTestItem * getTopTestItem()
{
    TTestItem *pItem = new TTestItem();
    pItem->addTest("Test schedule", []{ switchTestItem(addSheduleTest()); return true;});
    pItem->addExitItem();
    return pItem;
}

Scene* createTestScene()
{
    return switchTestItem(getTopTestItem());
}

