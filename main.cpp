#include <stdio.h>
#include <core/utils/Lock.h>
#include <unistd.h>
#include <iostream>
#include <core/utils/Collection.h>
#include <pthread.h>

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

int main(int argc, char *argv[])
{
    printf("[%d %s]\n", argc, argv[0]);

    {
        int *val = (int*)malloc(sizeof(int));
        safefree ((void**)&val);
        safefree ((void**)&val);
    }

    {
        int *val = (int*)malloc(sizeof(int));
        free(val); // error
    }

    {
        int *val = new int;
        safedelete<int**>(&val);
    }
    {
        int *val = new int;
//        delete(val); // error
//        delete val;
    }

    {
        int* val = new int[5];
//        delete(val); // error
//        delete[] val;
        safedelete<int*[]>(&val);
    }


//    pthread_t tid_put;
//    pthread_t tid_take;
//    pthread_create(&tid_put, 0, put, 0);
//    pthread_create(&tid_take, 0, take, 0);

//    pthread_join (tid_put, 0);
//    pthread_join (tid_take, 0);

    return 0;
}
