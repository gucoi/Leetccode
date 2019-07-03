/*
    题目:输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
 */

#include<limits.h>
class solution
{
    public:
    int Numberof1(int n){
        int count=0;
        //n为负数时 把n置为补码
        if(n<0){
            count++;
            n=INT_MAX+1+n;
        }
        while (n>0)
        {
            if(n&1)
                count++;
            n>>=1;
        }
        return count;
    }
};

