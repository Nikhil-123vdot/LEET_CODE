class Solution {
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            memset(child, 0, sizeof(child));
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node) {

        char c = board[i][j];

        if (c == '#' || !node->child[c - 'a'])
            return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }

        board[i][j] = '#';

        if (i > 0)
            dfs(board, i - 1, j, node);

        if (j > 0)
            dfs(board, i, j - 1, node);

        if (i + 1 < board.size())
            dfs(board, i + 1, j, node);

        if (j + 1 < board[0].size())
            dfs(board, i, j + 1, node);

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string& word : words)
            insert(word);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};