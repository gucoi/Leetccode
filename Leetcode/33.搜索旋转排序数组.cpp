/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        if(nums.size()!=0&&target>=nums[i]){
            for(;i<nums.size();i++){
                if(nums[i]==target){
                    return i;
                }
            }
        }
        else if(nums.size()!=0&&target<=nums.back()){
            i=nums.size()-1;
            for(;i>0;i--){
                cout<<2<<endl;
                if(nums[i]==target){
                    return i;
                }
            }
        }
        return -1;
    }
};

