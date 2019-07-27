# 二叉树的后序遍历

知识点：**二叉树的后序遍历顺序是 左节点->右节点->根节点**

例如下面给出一张二叉树图求出其后序排列数组

![二叉树](/图片资源/二叉树.png)

后序遍历: 4,7,8,5,2,6,3,1

代码展示 用递归解决蛮简单的

```C++
    vector<int> postorderTraversal(TreeNode *root){
        if(!root)return {};
        vector<int> res;
        _postorderTraversal(root,res);
        return res;
    }
    void _postorderTraversal(TreeNode* root, vector<int>& res){
        if(!root)return;
        _postorderTraversal(root->left,res);
        _postorderTraversal(root->right,res);
        res.push_back(root->val);
    }
```

