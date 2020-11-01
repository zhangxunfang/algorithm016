/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        solveNQueens(result, temp, 0, n);
        return result;
    }
    void solveNQueens(vector<vector<string>> &result, vector<string> &temp, int pos, int left) {
        int n = temp.size();
        // goal : we have no queens left, all queens are put in a proper pos
        if(left == 0) {
            result.push_back(temp);
            return;
        }
        // constrain 1, pos can't be greater than the size of the board
        else if(pos >= n*n) return;
        int row = pos/n, col = pos%n;
        // choice 1, with constrain 2, that is, the queens won't attack each other
        if(helper(temp, row, col)) {
            temp[row][col] = 'Q';
            solveNQueens(result, temp, pos+1, left-1);
            temp[row][col] = '.';
        }
        // choice 2
        solveNQueens(result, temp, pos+1, left);
    }
    bool helper(vector<string> &temp, int row, int col) {
        // check row
        for(int i = 0; i < row; ++i) {
            if(temp[i][col] == 'Q') {
                return false;
            }
        }
        // check col
        for(int i = 0; i < col; ++i) {
            if(temp[row][i] == 'Q') {
                return false;
            }
        }
        // check main diagnoal
        int r = row-1, c = col-1;
        while(r >= 0 && c >= 0) {
            if(temp[r--][c--] == 'Q') return false;
        }
        // check auxiliary diag
        r = row-1, c = col+1;
        while(r >= 0 && c < temp.size()) {
            if(temp[r--][c++] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end

