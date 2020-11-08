/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution
{
private:
    int getSum(int *bit, int idx)
    {
        int s = 0;
        for (; idx; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
    void update(int *bit, int n, int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        int n = nums.size(), inversions = 0;
        int temp[n];
        for (int i = 0; i < n; i++)
            temp[i] = nums[i];
        sort(temp, temp + n);
        int bit[n + 1];
        for (int i = 0; i < n + 1;i++) {
            bit[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(temp, temp + n, 2L * nums[i]) - temp;
            inversions += i - getSum(bit, index);
            index = upper_bound(temp, temp + n, nums[i]) - temp;
            update(bit, n, index, 1);
        }
        return inversions;
    }
};
// @lc code=end
