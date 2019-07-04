// '''
// 题目:输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
// '''
//注意：
// **这道题主要是用到了类似于冒泡排序的算法**
// **因为题目中有规定必须要保证奇数与奇数之间的相对位置相同**

#include<vector>
using namespace std;
class solution
{
public:
    void reOrderArray(vector<int>& array){
        for(int i=0;i<array.size();i++){
            for(int j=array.size()-1;j>i;j--){
                if(array[j]%2==1&&array[j-1]%2==0)
                    swap(array[j],array[j-1]);
            }
        }
    }

    //但是我之前没有考虑到要控制奇数之间相对位置不变,所以写的简单些 也放上代码当作错误典范
    /*
        void reOderArray(vector<int>& array){
            int i=0,j=array.size()-1;
            while(i<j){
                if(array[i]%2==0&&array[j]%2==1){
                    swap(array[i],array[j]);
                }
                if(array[i]%2==1){
                    i++;
                }
                if(array[j]%2==0){
                    j--;
                }
            }
        }
     */
};

