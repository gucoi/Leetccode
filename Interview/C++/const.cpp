/* 
 const名叫常量限定符，用来限定特定变量，以通知编译器该变量是不可修改的。
 习惯性的使用const，可以避免在函数中对某些不应修改的变量造成可能的改动。
 
(1)const修饰基本数据类型
 1.const修饰一般常量及数组
  
 基本数据类型，修饰符const可以用在类型说明符前，也可以用在类型说明符后，
 其结果是一样的。在使用这些常量的时候，只要不改变这些常量的值便好。 
  
 2.const修饰指针变量*及引用变量&  
 
如果const位于星号*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；

如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。

(2)const应用到函数中,  

 1.作为参数的const修饰符
 
 调用函数的时候，用相应的变量初始化const常量，则在函数体中，按照const所修饰的部分进行常量化,保护了原对象的属性。
 [注意]：参数const通常用于参数为指针或引用的情况; 
 
 2.作为函数返回值的const修饰符
 
 声明了返回值后，const按照"修饰原则"进行修饰，起到相应的保护作用。

(3)const在类中的用法

不能在类声明中初始化const数据成员。正确的使用const实现方法为：
const数据成员的初始化只能在类构造函数的初始化表中进行
类中的成员函数：A fun4()const; 其意义上是不能修改所在类的的任何变量。

(4)const修饰类对象，定义常量对象 
常量对象只能调用常量函数，别的成员函数都不能调用。
 
*/

#include<iostream>

using namespace std;

//const修饰符用于函数参数，在函数体中无法对其进行修改。
void func(const int&,const int&);
class A{

    public:
        //意义上该函数无法修改所在类的任何变量
        void func() const {
            // a=1; error;
        }
        A(int i)
        :a(i),j(i)
        {
            // const 数据成员只能在类构造函数的初始化表中进行
            //j=i; error
        } 
        const void func_const(){

        }
    private:
        const int j;
        int a;
};
int main(){
    //const修饰变量
    const int a=1;
    //const修饰数组
    const int array[10]={1,2,3,4,5};
    //无法对其进行修改
    // array[1]=3;
    //指针指向的内容无法修改，可以修改指针
    const int *pointer=new int(2);
    //无法对其进行修改
    // *pointer=100;
    int * const pointer_1=new int(3);
    //无法对指针进行修改
    // pointer_1=&a;
    
    //常量类对象只能调用常量函数 且必须要有构造函数
    const A a1(1);
    a1.func();
    // a1.func_const(); error
    
    // int a1=2;
    // pointer=&a1;
    // delete pointer;

    getchar();
    return 0;
}