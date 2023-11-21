class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int index, int i, int j) {
        int wordLen = word.size();
        int n = board.size();
        int m = board[0].size();

        if (wordLen == index) return true;

        if (i < 0 || j < 0 || i >= n || j >= m || word[index] != board[i][j]) return false;

        char temp = board[i][j];
        board[i][j] = '*';
        bool found = search(board, word, index+1, i+1, j) ||
            search(board, word, index+1, i, j+1) ||
            search(board, word, index+1, i-1, j) ||
            search(board, word, index+1, i, j-1);
        board[i][j] = temp;
        return found;
    }

};
