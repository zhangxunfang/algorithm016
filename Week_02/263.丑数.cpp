/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        // if (num <= 0) return false;
        // if (num == 1) return true; 
        // if (num % 2 == 0) {
        //     return isUgly(num / 2);
        // }
        // else if (num % 3 == 0) {
        //     return isUgly(num / 3);
        // }
        // else if (num % 5 == 0) {
        //     return isUgly(num / 5);
        // }
        // else {
        //     return false;
        // }
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};
// @lc code=end

