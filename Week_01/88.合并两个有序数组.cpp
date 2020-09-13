/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int Length = m + n;
        nums1.resize(Length);
        Length--;
        m--;
        n--;
        
        while (n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[Length--], nums1[m--]);
            }
            swap(nums1[Length--], nums2[n--]);
        }
        return;
    }
};
// @lc code=end

