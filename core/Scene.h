#ifndef SCENE_H
#define SCENE_H

#include <core/Node.h>

namespace rosefinch {


class Scene : public Node
{
public:
    Scene();
    ~Scene();
    void update(float dt);
private:
    void init();
    void render ();
};

}

#endif // SCENE_H
