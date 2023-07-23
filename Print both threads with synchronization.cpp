//C++ program that creates two threads. One thread should print all even numbers from 1 to 20, and the other thread should print all odd numbers from 1 to 20. Ensure that the output of both threads is synchronized correctly.

#include <iostream>
#include <thread>
#include <mutex>
 //<thread> for managing threads, and <mutex> for using mutexes for synchronization.
using namespace std;

mutex m;
// Create Mutex m
//m mutex is used to ensure synchronization, the two threads will take turns printing the numbers sequentially
void fun(int x)
//In the fun function, we pass an integer parameter x
{
    m.lock();
    //The function first acquires the lock on the mutex m using m.lock() to ensure that no other thread can access the critical section
    if(x==0)
    //If x is 0, it means the current thread is responsible for printing odd numbers from 1 to 20
    {
        for(int i=1;i<=20;i+=2)
        {
        cout<<i<<" ";
        }
        cout<<"\n";
    }
    else
    //If x is 1, it means the current thread is responsible for printing even numbers from 2 to 20
    {
        for(int i=2;i<=20;i+=2)
        {
        cout<<i<<" ";
        }
    }
    m.unlock();
    //After printing the numbers, the function releases the lock on the mutex using m.unlock() to allow other threads to access the critical section
}


int main()
{
    //two threads are created: To and Te
    thread To(fun,0);
    //The first thread (To) is responsible for printing odd numbers, so we pass 0 as the argument to the fun function
    thread Te(fun,1);
    //The second thread (Te) is responsible for printing even numbers, so we pass 1 as the argument to the fun function
    //Both threads are started simultaneously to execute the fun function
    To.join();
    Te.join();
    //join() function is called on both threads to wait for them to finish their execution before the program exits
    return 0;
}
