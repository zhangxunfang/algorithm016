/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> A;
        vector<int> B(2,-1);
        
        for (int i = 0;i < nums.size();i++) {
            if (A.count(target - nums[i]) > 0) {
                B[0] = A[target - nums[i]];
                B[1] = i;
                break;
            }
            A[nums[i]] = i;
        }
        return B;

    }
};
// @lc code=end

