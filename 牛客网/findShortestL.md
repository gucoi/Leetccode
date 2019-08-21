# 寻找最短递增数列的长度 其中每个元素是其他两个元素的和

<<<<<<< HEAD
示例
 
 `Input` `23`

`Output` `1 2 3 5 10 13 23`

这个是我的题解 我的思路是选择用set数据结构来筛出重复的元素，因为题目中给出了`A[0]=1,A[1]=2`的条件，所以先进行插入1，2两个值，然后判断Q值是否为2的开放数，如果不是2的次方数的话，最短递增数列中会出现3这个值（规律中查找到的），接着就遍历Q，

重复对Q进行遍历，直到Q值不大于3
>Q为奇数，将Q除2得值为S
>>如果S为偶数的话，将S，Q-S存入set中,然后将S值赋值为Q
>>如果S为奇数的话，将S-1，S+2存入set中，这样做的目的主要是保证S-1加上3与S+2相等，满足最短递增数列的要求，而且还可以凑出一个偶数这样保证了最短数列的最短特点，将S-1赋值给Q

>Q为偶数，将Q除2得值为S，将S存入set中,将S赋值给Q

```C++

int findShortestL(int Q){
    set<int> tem;
    tem.insert(1);
    tem.insert(2);
    if(Q>3&&!(pow(2,int(log2(Q)))==Q))
        tem.insert(3);
    tem.insert(Q);
    _findShortestL(Q,tem);
    for(auto i:tem){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
    return tem.size();
}
void _findShortestL(int Q,set<int>& tem){
    while(Q>3){
        if(Q%2==0){
            tem.insert(Q/2);
            Q/=2;
        }
        else{
            int S=Q/2;
            if(S%2==0){
                tem.insert(S);
                tem.insert(Q-S);
                Q=S;
            }
            else{
                tem.insert(S+2);
                Q-=S+2;
                tem.insert(Q);
            }
        }
    }
}


```

下面是某位金牌大佬的题解,用的是`dfs`

```C++
#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int roundef_log2[M + 5];
int ans[M + 5], Q, deep;

int get_rounded_log2(int x)/// 求 log2(x)
{
    int cnt = 0, mul = 1;
    while(mul < x)
        cnt++, mul *= 2;
    return cnt;
}

/**
2^(n - 1) = q
n - 1 = log2(q)
n = log2(q) + 1

现有步数 = log2(ans[cur]) + 1
总预估步数 = log2(q) + 1
还需步数 = log2(q) - log2(ans[cur])
         = log2(q / ans[cur])
**/

int predict(int cur)
{
    return roundef_log2[(int)ceil((double)Q / ans[cur])];
}

bool _findShortestL(int cur)
{
    bool fail[M + 5];
    memset(fail, 0, sizeof(fail));
    for(int i = cur; i >= 1; --i)
    {
        if(ans[i] * 2 <= ans[cur])///可行性剪枝 1
            break;
        for(int j = i; j >= 1; --j)
        {
            int num = ans[i] + ans[j];
            if(num < ans[cur])///可行性剪枝 2
                break;
            if(num <= Q && !fail[num])
            {
                ans[cur + 1] = num;
                int h = predict(cur + 1);
                if(h == 0)
                    return 1;
                else if(h + cur + 1 <= deep)
                {
                    if(_findShortestL(cur + 1))
                        return 1;
                    else
                        fail[num] = 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ans[1] = 1;
    scanf("%d", &Q);
    if(Q == 1)
        printf("1\n");
    else if(Q == 2)
        printf("1 2\n");
    else
    {
        for(int i = 1; i < M; ++i)
            roundef_log2[i] = get_rounded_log2(i);
        deep = 3;
        while(!_findShortestL(1))
            ++deep;
        printf("%d\n", deep);
        for(int i = 1; i <= deep; ++i)
            printf("%d%c", ans[i], i == deep ? '\n' : ' ');
    }
    return 0;
}

```