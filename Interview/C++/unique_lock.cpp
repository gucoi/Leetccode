#include <iostream>
#include <mutex>
#include <thread>
#include <list>

using namespace std;
class Comm
{
public:
    void Generate()
    {
        for (size_t i = 1; i < 100; i++)
        {
            //defer_lock 使用前提不能lock,他初始化一个没有lcok过的unique_lock
            //离开作用域,析构函数自动调用unlock函数
            // unique_lock<mutex> lock(mtx1,defer_lock);
            // lock.lock();
            // msg.push_back(i);
            // cout<<"Generate msg "<<i<<endl;

            //try_to_lock 尝试给互斥量加锁,加上返回true,加不上返回false,并不阻塞线程.
            //一定要注意 不阻塞线程这个特征 
            unique_lock<mutex> lock(mtx1, try_to_lock);
            if (lock.owns_lock())
            {
                cout << "catch the lock and generate " << i << endl;
                msg.push_back(i);
            }
            else
            {
                cout << "not catch the lock QAQ" << endl;
            }
        }
    }
    void Recive()
    {
        for (size_t i = 1; i < 100; i++)
        {
            // mtx1.lock();
            unique_lock<mutex> lock(mtx1);
            if (msg.empty())
            {
                cout << "empty" << endl;
            }
            else
            {
                cout << "Recive msg " << msg.front() << endl;
                msg.pop_front();
            }
            // unique_lock<mutex> lock(mtx1,try_to_lock);
            // if(lock.owns_lock()){
            //     cout<<"Recive msg : "<<msg.front()<<endl;
            //     msg.pop_front();
            // }
            // else{
            //     cout<<"do other"<<endl;
            // }
            // mtx1.unlock();
        }
    }

private:
    mutex mtx1;
    list<int> msg;
};
int main()
{
    Comm com;
    thread Submit(&Comm::Generate, &com);
    thread Recive(&Comm::Recive, &com);

    Submit.join();
    Recive.join();

    getchar();
    return 0;
}