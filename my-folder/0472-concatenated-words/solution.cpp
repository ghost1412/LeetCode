class TrieNode {
    public:
        TrieNode* child[26];
        bool isLeaf;

        TrieNode() {
            for (int i=0; i<26; i++) {
                child[i] = NULL;
            }
            isLeaf = false;
        }
};

class Trie {
    public: 
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* curr = root;
            for (int i=0; i<word.size(); i++) {
                int charAlpha = word[i]-'a';
                if (!curr->child[charAlpha]) {
                    curr->child[charAlpha] = new TrieNode();
                }
                curr = curr->child[charAlpha];
            }
            curr->isLeaf = true;
        }

        bool search(string word) {
            TrieNode* curr = root;
            for (int i=0; i<word.size(); i++) {
                int charAlpha = word[i]-'a';
                if (!curr->child[charAlpha]) return false;
                curr = curr->child[charAlpha];
            }
            return curr->isLeaf;
        }
};


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       // unordered_set<string> mp(words.begin(), words.end());
        Trie* trie = new Trie();
        for (auto word: words) {
            trie->insert(word);
        }

        vector<string> res;
        for (auto word: words) {
          //  mp.erase(word);
            if (wordBreak(word, trie->root)) {
                res.push_back(word);
            }
          //  mp.insert(word);
        }
        return res;
    }
        bool wordBreak(const string& s, TrieNode* root) {
            int n = s.size();
            vector<int> dp(n + 1, -1);

            dp[0] = 0; 

            for (int i=0; i<n; ++i) {
                if (dp[i] == -1) continue;
                TrieNode* curr = root;
                for (int j=i; j<n; j++) {
                    int idx = s[j]-'a';

                    if (!curr->child[idx]) break;
                    curr = curr->child[idx];
                    if (curr->isLeaf) {
                        dp[j+1] = max(dp[i]+1, dp[j+1]);
                    }
                }
            }

            

            return dp[n] >= 2;  
        }


};
