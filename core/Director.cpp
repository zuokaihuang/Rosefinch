#include "Director.h"
#include <core/utils/Time.h>
#include <core/utils/Logger.h>

using namespace rosefinch;

Director* Director::m_pDirector = nullptr;

Director* Director::getInstance(){
    if (m_pDirector == nullptr){
        m_pDirector = new Director();
    }
    return m_pDirector;
}

Director::Director():
    AutoRef(),
    m_bShouldClose(false),
    m_FrameCount(0)
{
    m_bShouldClose = false;
}

Director::~Director()
{

}

bool Director::shouldClose(){
    return m_bShouldClose;
}


void Director::update (){
    ++m_FrameCount;
    Time* now = Time::now ();
    Time sleepTime = {0, 16000*10};

    float dt = sleepTime.us () * 0.000001f;

    if (m_pNextScene != nullptr){
        m_pCurrentScene = m_pNextScene;
        m_pNextScene = nullptr;
    }

    do{

        if (m_pCurrentScene != 0){
            m_pCurrentScene->update (dt);
        }

    }while(0);


    now->sleep (&sleepTime);
    DLog("==>%ld, sleep:%f",m_FrameCount, dt );
}

void Director::release (){
    release_sp ();
}

void Director::runScene (Scene *scene){
    m_pNextScene = scene;
}


