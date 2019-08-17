/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n>0){
            char ch='A'+(--n)%26;
            res.insert(res.begin(),ch);
            n/=26;
        }
        return res;
    }
};

