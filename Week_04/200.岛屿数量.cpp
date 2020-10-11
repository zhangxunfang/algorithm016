/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;

        for (int i = 0;i < nr;i++) 
            for (int j = 0;j < nc;j++) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    backtrack(grid, i, j);
                }
            }
        return num_islands;

    }
private:
    void backtrack(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') backtrack(grid, r - 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') backtrack(grid, r, c - 1);
        if (r + 1 < nr && grid[r+1][c] == '1') backtrack(grid, r + 1, c);
        if (c + 1 < nc && grid[r][c+1] == '1') backtrack(grid, r, c + 1);
    }
};
// @lc code=end

