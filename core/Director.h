#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <core/Ref.h>
#include <core/utils/Logger.h>
#include <core/Scene.h>

namespace rosefinch {
class Director : AutoRef
{
public:
    static Director* getInstance();
    bool shouldClose();
    void update();
    void release();

    void runScene(Scene* scene);
private:
    Director();
    ~Director();
private:
    static Director* m_pDirector;
    bool m_bShouldClose;
    size_t m_FrameCount;

    Scene* m_pCurrentScene;
    Scene* m_pNextScene;
};
}


#endif // DIRECTOR_H
