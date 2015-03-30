#ifndef HELLOSCENE_H
#define HELLOSCENE_H

#include <rosefinch.h>

class HelloScene : public rosefinch::Scene
{
public:
    HelloScene();
    ~HelloScene();

    void init(){}
    void update(float dt){}
    void render(){}
};

#endif // HELLOSCENE_H
