# 寻找最短递增数列的长度 其中每个元素是其他两个元素的和

例
`Input`:`23`
`Output`:`1 2 3 5 10 13 23`

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

bool dfs(int cur)
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
                    if(dfs(cur + 1))
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
        while(!dfs(1))
            ++deep;
        printf("%d\n", deep);
        for(int i = 1; i <= deep; ++i)
            printf("%d%c", ans[i], i == deep ? '\n' : ' ');
    }
    return 0;
}

```