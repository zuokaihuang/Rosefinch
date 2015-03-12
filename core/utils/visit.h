#ifndef VISIT_H
#define VISIT_H

namespace rosefinch {
class Element;
class Visitor;

class Visitor{
public:
    virtual void Visit( Element *element) = 0;
};

class Element{
public:
    virtual void Accept( Visitor* visitor) = 0;
};

}


#endif // VISIT_H
