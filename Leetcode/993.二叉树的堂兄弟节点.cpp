/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//首先放上自己的错误代码
/*
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)return false;
        int x_level=0,y_level=0;
        if(findVal(root,x,x_level)!=findVal(root,y,y_level)&&x_level==y_level){
            return true;
        }
        return false;
    }
    //查找节点值和val相等的父亲节点 以及记录level：当前树的层数
    TreeNode* findVal(TreeNode* root,int val,int &level){
        if(!root)return nullptr;
        level++;
        if(root->left){
            if(val==root->left->val){
                return root;
            }
        }
        if(root->right){
            if(val==root->right->val){
                return root;
            }
        }
        return findVal(root->left,val,level);
        return findVal(root->right,val,level);
    }
    试了两种办法都是卡在第八十一个案例上
    给出案例 testcase: '[1,2,3,null,4,null,5]\n5\n4'
 */
//解题思路 采用哈希树数据结构存储每个节点的层数和父亲节点的值
//因为题目中给了树中节点值不相等 所以上述方法成立
class Solution {
public:
    bool isCousins(TreeNode* root,int x,int y){
        m.clear();
        dfs(root,nullptr,0);
        auto m_x=m[x];
        auto m_y=m[y];
        return m_x.first!=m_y.first&&m_x.second==m_y.second;
    }
    void dfs(TreeNode* children,TreeNode* parent,int depth){
        if(!children)return;
        m[children->val]=make_pair(parent,depth);
        dfs(children->left,children,depth+1);
        dfs(children->right,children,depth+1); 
    }
    private:
        unordered_map<int,pair<TreeNode*,int>> m; 
};

// class Solution {
// public:
//     bool isCousins(TreeNode* root, int x, int y) {
//         m_.clear();
//         dfs(root, nullptr, 0);
//         auto px = m_[x], py = m_[y];
//         return px.first != py.first && px.second == py.second;
//     }
// private:
//     unordered_map<int, pair<TreeNode*, int>> m_;
//     void dfs(TreeNode* root, TreeNode* parent, int depth) {
//         if (!root) return;
//         m_[root->val] = make_pair(parent, depth);
//         dfs(root->left, root, depth + 1);
//         dfs(root->right, root, depth + 1);
//     }
// };
