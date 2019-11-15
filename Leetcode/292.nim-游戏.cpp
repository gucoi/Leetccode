/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */
class Solution {
public:
    bool canWinNim(int n) {
        if(count%2!=0&&n<3)
            return true;
        if(n<0){
            return false;
        }
        return ++count&&canWinNim(n-1)||canWinNim(n-2)||canWinNim(n-2);
    }
    private:
        int count=1;
};

