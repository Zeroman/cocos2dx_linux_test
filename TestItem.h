/// @file TestItem.h
/// @brief 
/// @author Zeroman Yang <51feel@gmail.com>
/// 0.01
/// @date 2015-07-12


#pragma once

#include "cocos2d.h"
#include "ui/UIListView.h"
#include "ui/UIButton.h"

using namespace cocos2d;
using namespace cocos2d::ui;

typedef std::function<bool()> TTestFunc;
typedef std::list<std::string> TTestNameList;
typedef std::map<std::string, TTestFunc> TTestFuncMap;

class TTestItem {
    public:
        TTestFuncMap _mapTestFuncs;
        TTestNameList _listTestNames;

    public:
        TTestItem ();

    public:
        void addTest(std::string name, TTestFunc func);
        void addEvent(Ref *pSender, ListView::EventType type);
        void addBackItem();
        void addExitItem();
        Node* getistView() ;

    public:
        bool testBack();
        bool testExit();
};


Scene *switchTestItem(TTestItem *pItem);
