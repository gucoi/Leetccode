
/* 

使用shared_ptr控制对象的生命周期，常用来进行对象的创建，属于强引用，只要被shared_ptr引用该对象就不会被析构

weak_ptr是一种弱引用，常常用来侦查对象是否存在，不控制对象的生命期，
也不会增加对象的引用计数如果对象还存在没被析构那么可以通过成员函数进行提升为强引用

shared_ptr = weak_ptr.lock（）

提升和引用计数都是原子操作的。

 

scope_ptr可以解决重复释放内存泄漏

 Shared_ptr::reset()函数若没有传入参数，那么智能指针会停止对保存指针的所有权的共享，
共享资源的引用计数减一。如果传入一个对象则释放当前的对象，去管理新传入的对象
 
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<memory>

using namespace std;
class A{
    public:
        A(){}
        ~A(){
            cout<<"destructor"<<endl;
        }
        void func(){
            cout<<"A function"<<endl;
        }
};
void handle(weak_ptr<A> p){
    //弱指针转换成强指针
    shared_ptr<A> q=p.lock();
    if(q!=nullptr){
        q->func();
    }else{
        cout<<"A already destructor"<<endl;
    }
}
int main(){
    shared_ptr<A> p(new A());
    thread t1(handle,p);
    return 0;
} 