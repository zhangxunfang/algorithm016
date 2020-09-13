/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int real_k = k % nums.size();
        if ( real_k == 0) return;
        vector<int>nums_temp(2*real_k);
        copy(nums.begin(), nums.begin() + real_k, nums_temp.begin());
        copy(nums.end() - real_k, nums.end(), nums.begin());
        for(int i = nums.size() - real_k;i > 0;i = i - real_k) {
            if (i >= 2*real_k) {
                copy(nums.begin() + i - real_k, nums.begin() + i, nums.begin() + i);
            }
            else {
                if (i > real_k) {
                    for (int j = real_k;j < i;j++) nums_temp[j] = nums[j];
                    copy(nums_temp.begin() + i - real_k, nums_temp.begin() + i, nums.begin() + i);
                    copy(nums_temp.begin(), nums_temp.begin() + i -real_k, nums.begin() + real_k);
                } 
                else {
                    copy(nums_temp.begin(), nums_temp.begin() + i, nums.begin() + real_k);
                }
                                              
            }           
        }
        return;
    }
};
// @lc code=end

