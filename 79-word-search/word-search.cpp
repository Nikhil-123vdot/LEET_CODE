class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int k) {

        // Boundary check
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Character match nahi hua
        if (board[i][j] != word[k]) {
            return false;
        }

        // Pura word mil gaya
        if (k == word.size() - 1) {
            return true;
        }

        // Visited mark
        char temp = board[i][j];
        board[i][j] = '#';

        // 4 directions
        bool found =
            dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) ||
            dfs(board, word, i, j - 1, k + 1);

        // Backtracking
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};