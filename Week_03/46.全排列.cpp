/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos;i < nums.size();i++) {
            swap(nums[pos], nums[i]);
            backtrack(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }

    }
};
// @lc code=end

