#include "threadTest.h"
#include <iostream>
using std::cout;
using std::endl;

DWORD runDouble::run()
{
    if(run_event.isSet() )
        for(int i = 0; i < 20; i++)
            cout << "double " << 2*i << endl;

    return 0;
}

DWORD runTriple::run()
{
    if(run_event.isSet() )
        for(int i = 0; i < 20; i++)
            cout << "triple " << 3*i << endl;

    return 0;
}

void runBigLoop::runThread()
{
    for(int i = 0; i < 1000; i++)
        cout << " big loop " << (3 * i) + 2 << endl;
}

void main( void )
{
    try
    {
        runDouble obj2;
        runTriple obj3;
        runBigLoop obj4;
        threadPool pool;

        pool.start(obj4);
        pool.start(obj2);
        pool.start(obj3);
        pool.startThreads();

        SleepEx(5000,false);
        pool.KillThreads();
    }

    catch(...)
     {
        cout << "exception" << endl;
     } 

}