#ifndef NODE_H
#define NODE_H

#include <core/Ref.h>
namespace rosefinch {
class Node : public RefBase<Node>
{
public:
    Node();
    ~Node();

    void init() ;
    void update(float dt);
    void render();
};

}

#endif // NODE_H
