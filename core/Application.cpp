#include "Application.h"
#include <core/Director.h>

using namespace rosefinch;

#include <iostream>
using namespace std;

Application::Application()
{

}

Application::~Application()
{

}

void Application::run (){
    auto pDirector = Director::getInstance ();

    appDidFinishLaunching();
    while(pDirector->shouldClose () == false){
        pDirector->update ();
    }
    pDirector->release ();
}

