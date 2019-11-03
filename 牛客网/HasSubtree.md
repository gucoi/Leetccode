# 树的子结构

题目:**有二叉树A和B，查看B是不是A的子树**

具体思路：如果两个节点的值相等的话，从主树当前的节点和子树的根节点开始遍历，判断两个树是否相等，如果想等，返回true，不相等返回false，如果是false的话，开始丛主树找下一个跟子树根节点值相等的点，然后重复上面的操作。

本题我当时刷的时候录制了视频 [视频地址](https://www.bilibili.com/video/av58726755)

## HasSubtree

```C++
    bool HasSubtree(TreeNode* t1,TreeNode* t2){
        if(!t1||!t2)return false;
        bool flag=false;
        if(t1->val==t2->val){
            flag=equalTree(t1,t2);
        }
        if(!flag)HasSubtree(t1->left,t2);
        if(!flag)HasSubtree(t1->left,t2);
        return flag;
    }
```

## equalTree

`判断如果子树遍历完为空返回真，但如果子树没有遍历完，但是如果主树遍历完了返回假，如果节点不相同，标记为假直接返回，如果相等继续遍历，直到子树遍历完或者节点不相等
`

```C++
    bool equalTree(TreeNode* t1,TreeNode* t2){
        if(!t2)return true;
        if(!t1)return false;
        bool flag=true;
        if(t1->val!=t2->val){
            flag=false;
        }
        if(flag)flag=equalTree(t1->left,t2->left);
        if(flag)flag=equalTree(t1->right,t2->right);
        
        return flag;
    }
```