#ifndef APPDELEGATE_H
#define APPDELEGATE_H

#include <rosefinch.h>
#include "HelloScene.h"

class AppDelegate : public Application
{
public:
    AppDelegate();
    ~AppDelegate();
    void appDidFinishLaunching();

};

#endif // APPDELEGATE_H
