/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        // int rows = matrix.size(), cols = matrix[0].size();
        // std::cout<<rows<<','<<cols<<std::endl;
        // int max = INT_MIN;
        // int dp[6][6][6][6] = {};
        // for (int i1 = 1; i1 <= rows; i1++)
        // {
        //     for (int j1 = 1; j1 <= cols; j1++)
        //     {
        //         dp[i1][j1][i1][j1] = matrix[i1 - 1][j1 - 1];
        //         for (int i2 = i1; i2 <= rows; i2++)
        //         {
        //             for (int j2 = j1; j2 <= cols; j2++)
        //             {
        //                 dp[i1][j1][i2][j2] = dp[i1][j1][i2 - 1][j2] + dp[i1][j1][i2][j2 - 1] - dp[i1][j1][i2 - 1][j2 - 1] + matrix[i2 - 1][j2 - 1];
        //                 if (dp[i1][j1][i2][j2] <= k && dp[i1][j1][i2][j2] > max)
        //                     max = dp[i1][j1][i2][j2];
        //             }
        //         }
        //     }
        // }
        // return max;
        if (matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int l = 0; l < col; ++l)
        {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r)
            {
                for (int i = 0; i < row; ++i)
                {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums)
                {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end())
                        curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                res = std::max(res, curMax);
            }
        }
        return res;
    }
};
// @lc code=end
