// 给定一个二叉树，计算整个树的坡度。

// 一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

// 整个树的坡度就是其所有节点的坡度之和。

// 示例:

// 输入: 
//          1
//        /   \
//       2     3
// 输出: 1
// 解释: 
// 结点的坡度 2 : 0
// 结点的坡度 3 : 0
// 结点的坡度 1 : |2-3| = 1
// 树的坡度 : 0 + 0 + 1 = 1
// 注意:

// 任何子树的结点的和不会超过32位整数的范围。
// 坡度的值不会超过32位整数的范围。

#include<iostream>
#include<math.h>
#include<stack>
using std::stack;

struct TreeNode
{
  TreeNode *right;
  TreeNode *left;
  int val;
};

class solution{
  //获取节点的左右节点值  
  int get_val(TreeNode* root){
      int sum=0;
      if(root)
        _get_val(root,sum);
      return sum;
    }
  //通过递归求得root的左右节点的值
    int _get_val(TreeNode* root,int &sum){
      if(root){
        sum+=root->val;
        _get_val(root->left,sum);
        _get_val(root->right,sum);
      }
      else return 0;
    }
  //
  int findTilt(TreeNode* root){
    if(!root)
      return 0;
    stack<TreeNode*> temStack;
    temStack.push(root);
    int sum=0;
    //开始一层一层的遍历树
    while(!temStack.empty()){
      TreeNode* temp=temStack.top();
      temStack.pop();
      //左右节点都存在时
      if(temp->left&&temp->right){
         temStack.push(temp->right);
         temStack.push(temp->left);
         //计算该节点的坡值
         sum+=abs(get_val(temp->right)-get_val(temp->left));
      }
      //只有左节点存在时
      else if(temp->left&&!temp->right){
        temStack.push(temp->left);
        sum+=abs(get_val(temp->left));
      }
      //只有右节点存在时
      else if(!temp->left&&temp->right){
        temStack.push(temp->right);
        sum+=abs(get_val(temp->right));
      }
    }
    return sum;
  }  
};
