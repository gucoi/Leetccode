# 二叉树的镜像

## 题目：操作给定的二叉树，将其变换为源二叉树的镜像

讲道理这道题我一开始想错了，我竟然想直接互换两个节点携带的值就行，可是实际上不是这样的可是他却报错说是超出栈列，后来我终于想到了问题所在只换值的话的确不能达到递归的结束条件

不多bb下面直接上代码
>递归版的

```C++
    void Mirror(TreeNode* Root){
        if(!Root){
            return;
        }
        //C++11引入了可以交换指针的swap方法
        swap(Root->left,Root->right);
        if(Root->left){
            Mirror(Root->left);
        }
        if(Root->right){
            Mirror(Root->right);
        }
    }
```

>非递归版的

```C++
    void Mirror(TreeNode* Root){
        //错误处理
        if(!Root)return;
        stack<TreeNode*> tem;
        tem.push(Root);
        while(!tem.empty()){
            TreeNode* tempTreeNode=tem.top();
            tem.pop();
            if(tempTreeNode->left||tempTreeNode->right){
                swap(tempTreeNode->left,tempTreeNode->right;
            }
            //压入一个空值无所谓的
            if(tempTreeNode->left){
                tem.push(tempTreeNode->left);
            }
            if(tempTreeNode->right){
                tem.push(tempTreeNode->right);
            }
        }
    }
```
