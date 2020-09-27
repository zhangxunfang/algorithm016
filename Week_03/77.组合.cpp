/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    //  vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>> res;
    //     backtrack(res, 1, n, k, vector<int>());
    //     return res;
    // }
    
    // void backtrack(vector<vector<int>>& res, int cur, int n, int k, vector<int> comb){
    //     if(k == 0){
    //         res.push_back(comb);
    //         return;
    //     }
    //     // If cur>n-k, there are not enough numbers left, we have to select the current element
    //     if(cur <= n - k) backtrack(res, cur + 1, n, k, comb);  
    //     comb.push_back(cur);
    //     backtrack(res, cur + 1, n, k - 1, comb);
    // }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        backtrack(res, n, k, vector<int>());
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, int n, int k, vector<int>comb){
        if(k == 0) {
            res.push_back(comb);
            return;
        }
        if(n > k) backtrack(res, n-1, k, comb);
        comb.push_back(n);
        backtrack(res, n-1, k-1, comb);
    }
};
// @lc code=end

