class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index == word.size()) return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[index] !=  board[i][j]) return false;
        index++;
        char temp = board[i][j];
        board[i][j] = '*';
        bool found = search(board, word, index, i+1, j) || search(board, word, index, i, j+1)
        || search(board, word, index, i-1, j) || search(board, word, index, i, j-1);
        board[i][j] = temp;
        return found;

    }
};
