#include "AppDelegate.h"
#include <rosefinch.h>

using namespace rosefinch;

AppDelegate::AppDelegate():
    Application()
{

}

AppDelegate::~AppDelegate()
{

}

void AppDelegate::appDidFinishLaunching(){
    auto pDirector = Director::getInstance ();

    HelloScene* helloScene = (HelloScene*)HelloScene::create ();
    pDirector->runScene (helloScene);

}

