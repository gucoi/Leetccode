#include<iostream>
#include<deque>
#include<iterator>
#include<algorithm>

using namespace std;
int main(){
    int a[]={0,1,2,3,4,5,6};
    deque<int> id(a,a+6);
    //cout绑定到out迭代器上
    ostream_iterator<int> out(cout," * ");
    copy(a,a+6,out);
    cout<<endl;
    //将a数组中的部分元素使用front_insert拷贝到id中
    //front_insert会将assign操作改为push_front操作

    copy(a+1,a+2,front_inserter(id));
    copy(id.begin(),id.end(),out);
    cout<<endl;

    copy(a+3,a+4,back_inserter(id));
    copy(id.begin(),id.end(),out);
    cout<<endl;

    //找到deque中位置5的迭代器
    deque<int>::iterator ite=find(id.begin(),id.end(),5);
    //将a[]的部分元素拷贝到id内，使用insert_interato.r
    copy(a,a+3,inserter(id,ite));
    copy(id.begin(),id.end(),out);
    cout<<endl;
    //将所有元素逆向插入到out中
    copy(id.rbegin(),id.rend(),out);
    cout<<endl;

    getchar();
    return 0;
}