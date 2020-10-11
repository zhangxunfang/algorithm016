/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || click.empty()) return {};
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        backtrack(board, visited,click[0], click[1]);
        return board;
    }
private:
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    void backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        if (min(r, c) < 0 || r >= board.size() || c >= board[0].size() || visited[r][c]) return;
        visited[r][c] = true;
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return;
        }

        if (board[r][c] == 'E') {
            int count = hasAdjacentMine(board, r, c);
            if (count == 0) {
                board[r][c] = 'B';
                for (int k = 0;k < 8;k++) {
                    backtrack(board, visited, r + dx[k], c + dy[k]);
                }
            }
            else {
                board[r][c] = count + '0';
                return;
            }
        }
    }
    bool isValid(vector<vector<char>>& board, int i, int j) {
        return (i >= 0 && j >= 0 && i < board.size() && j < board[0].size());
    }
    int hasAdjacentMine(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        for (int k=0; k<8; k++) {
            int I = i + dx[k];
            int J = j + dy[k];
            if (isValid(board, I, J) && board[I][J] == 'M')
                count++;
        }
        return count;
    }
};
// @lc code=end

