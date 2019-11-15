
写在最前面,借鉴于这位大佬的[可以点这儿，过去看一下](https://www.acwing.com/blog/content/461/)

# 两种常用的搜索方式

## BFS

* 优缺点
  * 空间是指数级别的 大！！！
  * 不会有爆栈的风险
  * 可以搜最短，最小

代码模板

```C++
    queue<int> q;
    st[0] = true; // 表示1号点已经被遍历过
    q.push(0);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!s[j])
            {
                st[j] = true; // 表示点j已经被遍历过
                q.push(j);
            }
        }
    }
```

典型例题

1. [完全平方数](https://leetcode-cn.com/problems/perfect-squares/submissions/)
2. [走迷宫](https://www.acwing.com/problem/content/description/846/)
3. [层序遍历](https://www.acwing.com/problem/content/42/)

## DFS

* 优缺点
  * 容易爆栈 如果树有`1e4`层，就爆了
  * 空间和深度成正比，相对较小
  * 不能搜最短、最小

思考方式&&代码模板

```C++
void dfs()//参数用来表示状态  
{  
    if(到达终点状态)  
    {  
        ...//根据题意添加  
        return;  
    }  
    if(越界或者是不合法状态)  
        return;  
    if(特殊状态)//剪枝
        return ;
    for(扩展方式)  
    {  
        if(扩展方式所达到状态合法)  
        {  
            修改操作;//根据题意来添加  
            标记；  
            dfs（）；  
            (还原标记)；  
            //是否还原标记根据题意  
            //如果加上（还原标记）就是 回溯法  
        }  

    }  
}

```

典型的深度搜索加回溯处理问题

1. [单词搜索](https://leetcode-cn.com/problems/word-search/submissions/)
2. [单词排列](https://leetcode-cn.com/problems/permutations/submissions/)

单词搜索例题 代码

```C++
class Solution {
public:
    vector<vector<char>> board;
    string word;
    int n;
    int h,w;
    bool exist(vector<vector<char>>& _board, string _word) {
        board=_board;
        word=_word;
        n=_word.size();
        h=board.size();
        if(!h)return true;
        w=board[0].size();
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(dfs(i,j,0))
                    return true;
        return false;
    }
    bool dfs(int x,int y,int u){
        if(board[x][y]!=word[u])return false;
        if(u==n-1)return true;
        auto t=board[x][y];
        board[x][y]='*';
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<h&&b>=0&&b<w){
                if(dfs(a,b,u+1))return true;
            }
        }
        board[x][y]=t;
        return false;
    }
};
```

单词排列 例题代码，可以看一下是怎么**回溯**处理的

```C++
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        st=vector<bool>(n+1);
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>& nums,int u){
        if(u==n-1){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;i++){
            if(!st[i]){
                st[i]=true;
                path.push_back(nums[i]);
                dfs(nums,u+1);
                path.pop_back(nums[i]);
                st[i]=false;
            }
        }
    }
};
```
