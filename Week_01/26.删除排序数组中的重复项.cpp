/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int SingleIndex = 0;
        for (int i = 1;i < nums.size();i++) {
            if (nums[SingleIndex] != nums[i])
            nums[++SingleIndex] = nums[i];
        }

        return SingleIndex + 1;
    }
};
// @lc code=end

