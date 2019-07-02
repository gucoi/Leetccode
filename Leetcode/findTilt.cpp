class solution{
  //获取节点的左右节点值  
  void get_val(TreeNode* root){
      int sum=0;
      if(root)
        _get_val(root,sum);
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
        sum+=abs(get_val(temp->left);
      }
      //只有右节点存在时
      else if(!temp->left&&temp->right){
        temStack.push(temp->right);
        sum+=abs(get_val(temp->right);
      }
    }
    return sum;
  }  
};
