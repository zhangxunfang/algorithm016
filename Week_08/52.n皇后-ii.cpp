/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
// class Solution
// {
// public:
//     int totalNQueens(int n)
//     {
//         vector<bool> col(n, true);
//         vector<bool> anti(2 * n - 1, true);
//         vector<bool> main(2 * n - 1, true);
//         vector<int> row(n, 0);
//         int count = 0;
//         dfs(0, row, col, main, anti, count);
//         return count;
//     }
//     void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool> &main, vector<bool> &anti, int &count)
//     {
//         if (i == row.size())
//         {
//             count++;
//             return;
//         }
//         for (int j = 0; j < col.size(); j++)
//         {
//             if (col[j] && main[i + j] && anti[i + col.size() - 1 - j])
//             {
//                 row[i] = j;
//                 col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
//                 dfs(i + 1, row, col, main, anti, count);
//                 col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
//             }
//         }
//     }
// };
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }


private:
    int res = 0;
};
// @lc code=end
