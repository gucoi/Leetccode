// 饿汉模式 每次运行时初始化单例实例
#include<iostream>
#include<string>
#include<list>
using namespace std;

//静态变量的初始化顺序不确定

class Log{
    public:
        static Log* Instance(){
            return &m_instance;
        }
    private:
        Log(){
            cout<<" constructor "<<endl;
        }
        Log(const char*);
        Log& operator=(const Log&);
        //直到程序销毁 才会调用析构函数
        static Log m_instance;
        static list<string> m_data;
};

Log Log::m_instance;
list<string> Log::m_data;

int main(){
    Log* p=Log::Instance();

    getchar();
    return 0;
}