class TrieNode {
    public:
        TrieNode* child[26];
        bool isLeaf;

        TrieNode() {
            isLeaf = false;
            for (int i=0; i<26; i++) {
                child[i] = NULL;
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
        for(int i=0; i<word.size(); i++) {
            int charVal = word[i] - 'a';
            if (!p->child[charVal]) {
                p->child[charVal] = new TrieNode();
            }
            p = p->child[charVal];
        }
        p->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++) {
            int charVal = word[i] - 'a';
            if (!p->child[charVal]) return false;
            p = p->child[charVal];
        }
        return p->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0; i<prefix.size(); i++) {
            int charVal = prefix[i] - 'a';
            if (!p->child[charVal]) return false;
            p = p->child[charVal];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
