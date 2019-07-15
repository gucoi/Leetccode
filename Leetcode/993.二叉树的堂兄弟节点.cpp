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
class Solution {
public:
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
};

