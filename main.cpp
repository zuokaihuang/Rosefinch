#include <stdio.h>
#include <core/utils/Lock.h>
#include <unistd.h>
#include <iostream>
#include <core/utils/Collection.h>
#include <pthread.h>

#include <core/Ref.h>
#include <core/utils/Memory.h>

using namespace rosefinch;
using namespace std;


MessageQueue<int> mq;

Condition cond;

void* put(void*){
    int cnt=0;
    while(cnt++<10){
        mq.Put (cnt);
    }
    return 0;
}

void * take(void*){
    while(true){
        int val = mq.Take ();
        cout << "val:" << val << endl;
    }
}

//class Student : public RefBase<Student>{
//public:
//    Student():RefBase(){cout << "constructor" << endl;}
//    virtual ~Student(){cout << "deconstructor" << endl;}
//    void init(){}
//};

class Student : public Ref {
public:
    Student():Ref(){cout << "constructor" << endl;}
    virtual ~Student(){cout << "deconstructor" << endl;}
    void init(){}
};

class Teacher : public RefBase<Teacher>{
public:
    Teacher():RefBase(){cout << "constructor" << endl;}
    virtual ~Teacher(){cout << "deconstructor" << endl;}
    void init(){}
};

int _main(int argc, char *argv[])
{
    printf("[%d %s]\n", argc, argv[0]);

//    pthread_t tid_put;
//    pthread_t tid_take;
//    pthread_create(&tid_put, 0, put, 0);
//    pthread_create(&tid_take, 0, take, 0);

//    pthread_join (tid_put, 0);
//    pthread_join (tid_take, 0);

//{
////    Student *pStu = Student::create ();
//    Student *pStu = new Student();

////    RefBase<Student>* refbaic =  pStu;
////    Ref* ref = pStu;

//    cout << pStu << endl;
//    AutoRef af;
//    af.add ((Ref*&)pStu);

//    cout << "hi" << af.size ()<< endl;
//    af.release ();
//    cout << af.size ()<< endl;

//    cout << pStu << endl;
//}


//    {
//    //    Student *pStu = Student::create ();
//        Student *pStu = new Student();

//    //    RefBase<Student>* refbaic =  pStu;
//    //    Ref* ref = pStu;

//        sp<Ref>* mSp = new sp<Ref>((Ref**)&pStu);

//        cout << *(*mSp) << endl;
//        AutoRef af;
//        af.add_sp (mSp);

//        cout << af.size ()<< endl;
//        af.release_sp ();
//        cout << af.size ()<< endl;

//        cout << "delete:" << *(*mSp) << endl;
//    }

    {
        Teacher *pStu = Teacher::create ();

        sp<Ref>* mSp = new sp<Ref>((Ref**)&pStu);

        cout << *(*mSp) << endl;
        AutoRef af;
        af.add_sp (mSp);

        cout << af.size ()<< endl;
        af.release_sp ();
        cout << af.size ()<< endl;

        cout << "delete:" << mSp->get ()<< endl;
    }

    return 0;
}
