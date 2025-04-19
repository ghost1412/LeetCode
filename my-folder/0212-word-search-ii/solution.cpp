class TrieNode {
    public:
        TrieNode* child[26];
        bool isLeaf;
        string word;
        TrieNode() {
            isLeaf = false;
            word="";
            for(int i=0; i<26;i++){
                child[i]=NULL;
            }
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* p = root;
            for (int i=0;i<word.size(); i++) {
                int childVal = word[i]-'a';
                if (!p->child[childVal]) {
                    p->child[childVal] = new TrieNode();
                }
                p = p->child[childVal];
            }
            p->isLeaf = true;
            p->word = word;
        }

        bool search(string word) {
            TrieNode* p = root;
            for(int i=0; i<word.size(); i++) {
                int childVal = word[i]-'a';
                if (!p->child[childVal]) return false;
                p = p->child[childVal];
            }
            return p->isLeaf;
        }
};

class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    void searchPos(vector<vector<char>> & board, TrieNode* root, vector<string>&res, int i, int j) {
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == '$' || root->child[board[i][j]-'a'] == NULL) return;

        root = root->child[board[i][j]-'a'];
        if (root->isLeaf) {
            res.push_back(root->word);
            root->isLeaf = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir:directions){
            searchPos(board, root, res, i+dir[0], j+dir[1]);
        }
        board[i][j] = temp;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* root = new Trie();
        for (int i=0; i<words.size(); i++) {
            root->insert(words[i]);
        }
        for(int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                searchPos(board, root->root, res, i, j);
            }
        }
        return res;
    }
};
