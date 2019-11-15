//懒汉模式 单例只在第一次被使用时初始化

#include<iostream>
#include<list>
#include<string>

using namespace std;
//不完美版(堆栈)
class LogNotPerfect{
    public:
        static LogNotPerfect* Instance(){
            if(m_instance==nullptr){
                cout<<"instance created only once";
                m_instance=new LogNotPerfect();
                //为了释放资源
                static Destory de;
                return m_instance;
            }
            else return m_instance;
        }
        virtual void Write(const char*);
        virtual bool SavaTo(const char* fileName);
    private:
        //为了在程序结束时释放分配的资源
        class Destory{
            public:
                ~Destory(){
                    if(m_instance!=nullptr){
                        delete m_instance;
                    }
                    m_instance=nullptr;
                }
        };
        LogNotPerfect();
        LogNotPerfect(const LogNotPerfect&);
        LogNotPerfect& operator=(const LogNotPerfect&);
        static LogNotPerfect* m_instance;
        static list<string> m_data;
};

list<string> LogNotPerfect::m_data;
LogNotPerfect* LogNotPerfect::m_instance=NULL;

//完美版（局部静态变量）
class Log{
    private:
        Log();//constructor hid
        Log(const Log&);//ctor hid
        Log& operator =(const Log&);//assign op is hidden
        static list<string> m_data;
    public:
        virtual void Write(const char*);
        virtual bool SaveTo(const char* fileName);
        //返回引用值，能够避免不小心释放或者验证是否为空指针的步骤
        static Log& Instance(){
            //静态局部变量的好处，thelog的构造函数只会被调用一次
            static Log thelog;
            return thelog;
        }
};
//需要提前对他进行初始化
list<string> Log::m_data;