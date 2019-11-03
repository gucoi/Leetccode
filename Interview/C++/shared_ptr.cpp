#include <iostream>
#include<algorithm>

using namespace std;

template <class T>
class Shared_ptr
{
public:
/* 
    nullptr与NULL之间的区别 https://blog.csdn.net/justdoithai/article/details/51492133
*/
    Shared_ptr()
        : ptr(nullptr), count(new int(0))
    {
    }
    Shared_ptr(T *Pptr)
        : ptr(Pptr), count(new int)
    {
    }
    //析构函数
    ~Shared_ptr()
    {
        (*count)--;
        if (*count == 0)
        {
            cout << "空间释放";
            delete count;
            try
            {
                if (ptr)
                {
                    delete ptr;
                    ptr = nullptr;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
/* 
    移动构造函数是将原来的内存利用起来，过去的对象清空，比如T t(move(t1));这样的t1的对象为空，
*/
    //移动构造函数
    Shared_ptr(Shared_ptr&& e)
    :ptr(e.ptr),count(e.count)
    {
        (*e.count)++;
    }
    //拷贝赋值运算符
    Shared_ptr& operator =(const Shared_ptr& e){
        Shared_ptr(move(e));
    }
    //拷贝构造函数
    Shared_ptr(const Shared_ptr &m)
    {
        *count = *m.count;
        ptr = m.ptr;
        (*m.count)++;
    }
    //重载解引用运算符
    T& operator *(){
        return *ptr;
    }
    //重载箭头运算符
    T* operator ->(){
        return ptr;
    }
private:
    T *ptr;
    int *count;
};

int main()
{
    Shared_ptr<int> p(new int);
    *p=1;

    getchar();
}