#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

class Comm
{
private:
    Comm() {}
    //为了方便释放分配的资源
    class AuxCls
    {
    public:
        ~AuxCls()
        {
            if (m_instance)
            {
                delete m_instance;
                m_instance = nullptr;
            }
        }
    };

public:
    /* 
        call_once 调用线程安全 比如两个线程同时进行到这,A线程抢先执行call_once,
        那么B线程和其他所有线程都不可以执行call_once,如果A线程执行完毕,就通过once_flag位
        告知其他线程不必执行这个线程,通过这种方式,实现call_once方法
    */
    static Comm *GetInstance()
    {
        call_once(one_flag, CreateInstance);
        return m_instance;
    }

private:
    static void CreateInstance()
    {
        m_instance = new Comm();
        static AuxCls a;
    }
    static Comm *m_instance;
    static once_flag one_flag;
};

//类静态成员的初始化
Comm *Comm::m_instance = nullptr;
once_flag Comm::one_flag;

void create() { Comm::GetInstance(); }

int main()
{

    Comm *ptr = Comm::GetInstance();
    thread t1(create);
    thread t2(create);

    t1.join();
    t2.join();

    getchar();
    return 0;
}