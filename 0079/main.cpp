// 79. Word Search
// https://leetcode.com/problems/word-search/
/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; ++i) {
            visited.push_back(vector<bool>(n, false));
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }


private:
    int m, n;

    int d[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool dfs(const vector<vector<char>> &board, int x, int y, const string &word, int index) {
        if (index >= word.size()) {
            return false;
        }
        if (board[x][y] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if (inArea(newX, newY) && !visited[newX][newY]) {
                visited[x][y] = true;
                if (dfs(board, newX, newY, word, index + 1)) {
                    return true;
                }
                visited[x][y] = false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };

    cout << Solution().exist(board, "ABCCED") << endl;
    cout << Solution().exist(board, "SEE") << endl;
    cout << Solution().exist(board, "ABCB") << endl;
    return 0;
}
// Runtime: 16 ms, faster than 90.33% of C++ online submissions for Word Search.