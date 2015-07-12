/// @file TestItem.cpp
/// @brief 
/// @author Zeroman Yang <51feel@gmail.com>
/// 0.01
/// @date 2015-07-12


#include "TestItem.h"
#include "_debug.h"

using namespace cocos2d;
using namespace cocos2d::ui;


TTestItem::TTestItem ()
{
}

void TTestItem::addTest(std::string name, TTestFunc func) 
{
    _mapTestFuncs[name] = func;
    _listTestNames.push_back(name);
}

void TTestItem::addEvent(Ref *pSender, ListView::EventType type)
{
    switch (type)
    {
        case ListView::EventType::ON_SELECTED_ITEM_START:
            break;
        case ListView::EventType::ON_SELECTED_ITEM_END:
            {
                ListView* listView = static_cast<ListView*>(pSender);
                CC_UNUSED_PARAM(listView);
                // CCLOG("select child end index = %ld", listView->getCurSelectedIndex());
                Button *pBtn = (Button *)listView->getItem(listView->getCurSelectedIndex());
                CCLOG("name = %s", pBtn->getName().c_str());
                auto func = _mapTestFuncs[pBtn->getName()];
                if (func)
                    func();
                break;
            }
        default:
            break;
    }
}

bool TTestItem::testBack()
{
    Director::getInstance()->popScene();
    delete this;
    return true;
}

bool TTestItem::testExit()
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    return true;
}

void TTestItem::addBackItem()
{
    addTest("Back", std::bind(&TTestItem::testBack, this));
}

void TTestItem::addExitItem()
{
    addTest("Exit", std::bind(&TTestItem::testExit, this));
}

Node* TTestItem::getistView() 
{
    ListView* _listView;
    Size visibleSize = Director::getInstance()->getVisibleSize();

    _listView = ListView::create();
    _listView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _listView->setTouchEnabled(true);
    _listView->setBounceEnabled(true);
    _listView->setBackGroundColor(Color3B(0, 0, 0));
    _listView->setBackGroundImageScale9Enabled(true);
    _listView->setContentSize(Size(visibleSize.width - 80, visibleSize.height - 50));
    _listView->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 2));
    auto cb = std::bind(&TTestItem::addEvent, this, std::placeholders::_1, std::placeholders::_2);
    _listView->addEventListener((ListView::ccListViewCallback(cb)));
    _listView->setGravity(ListView::Gravity::CENTER_HORIZONTAL);
    _listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _listView->setItemsMargin(5.0f);

    for (auto ip : _listTestNames) {
        Button* btn = Button::create("res/btn_normal.png", "res/btn_press.png");
        btn->setName(ip);
        btn->setTitleFontSize(24);
        btn->setScale9Enabled(true);
        btn->setTitleText(ip);
        btn->setContentSize(Size(visibleSize.width - 120, 50));
        _listView->addChild(btn);
    }
    return _listView;
}

Scene *switchTestItem(TTestItem *pItem)
{
    Scene *scene = Scene::create();
    scene->addChild(pItem->getistView());
    Director::getInstance()->pushScene(scene);
    return scene;
}

