/*
static

控制变量的存储方式和可见性。 

(1)修饰局部变量

一般情况下，对于局部变量是存放在栈区的，并且局部变量的生命周期在该语句块执行结束时便结束了。
但是如果用static进行修饰的话，该变量便存放在静态数据区，
其生命周期一直持续到整个程序执行结束。
但是在这里要注意的是，虽然用static对局部变量进行修饰过后，其生命周期以及存储空间发生了变化，
生命周期长于局部函数
但是其作用域并没有改变，其仍然是一个局部变量，作用域仅限于该语句块。
只初始化一次

(2)修饰全局变量

对于一个全局变量，它既可以在本源文件中被访问到，
也可以在同一个工程的其它源文件中被访问(只需用extern进行声明即可)。
用static对全局变量进行修饰改变了其作用域的范围，由原来的整个工程可见变为本源文件可见。

(3)修饰函数

用static修饰函数的话，情况与修饰全局变量大同小异，就是改变了函数的作用域。

(4)C++中的static

如果在C++中对类中的某个函数用static进行修饰，则表示该函数属于一个类而不是属于此类的任何特定的对象
如果对类中的某个对象进行static修饰，表示该变量为类以及其所有的对象所有
它们在内存中只存在一个副本，容许类和对象去调用
static修饰的对象可以被继承，但是无法实现多态


*/
#include<iostream>
#include<memory>
using namespace std;

class A{
    public:
        A()
        {
            cout<<"A constructure\n";
        }
        void Display(){
            cout<<j;
        }
        void set_a(int i){
            j=i;
        }
        static void print(){
            //静态成员函数不能调用类中非静态成员对象
            // cout<<M_i<<endl;
            //可以调用静态成员
            cout<<j;
        }
    private:
    static int j;
    int M_i;
};

int test(){
    //只初始化一次
    static int i=0;
    cout<<i++<<' ';
} 
 
//类的静态成员使用之前必须要进行初始化
int A::j=0;

template<class type>
type* lloc(int size){
    return new type[size];
}

int main(){
    A a;
    a.set_a(2);
    A b;
    a.print();

    A* tem=lloc<A>(10);
    delete [] tem;
    
    //static 修饰局部变量只初始化一次之后便不初始化
    // for(int i=0;i<10;i++)
    //     test();

    b.Display();
    getchar();
    return 0;
}