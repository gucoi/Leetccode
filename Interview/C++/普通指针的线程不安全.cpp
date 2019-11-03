#include<memory>
#include<iostream>
#include<thread>

using namespace std;
class A{
    public:
    A(){}
    void func(){
        cout<<"A function"<<endl;
    }
    ~A(){
        cout<<"destructor "<<endl;
    }
};
int main(){
    //这样写的话，及其不安全，根据输出来看出现了指针析构
    A* ptr=new A();
    thread t1(&A::func,ptr);
    delete ptr;
    t1.join();
    getchar();
    return 0;
}