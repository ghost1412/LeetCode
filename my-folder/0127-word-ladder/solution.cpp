class Solution {
public:

    bool isOneDiffAway(string a, string b) {
        int diff = 0;
        for (int i=0; i<a.size(); i++) {
            if (a[i]!=b[i]) diff++;
            if (diff>1) return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       // unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>>  q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [currWord, level] = q.front();
            q.pop();
            for (auto it=wordSet.begin(); it!=wordSet.end(); ) {
                string nextWord = *it;
                if (isOneDiffAway(currWord, nextWord)) {
                    if (nextWord == endWord) return level+1;
                    q.push({nextWord, level+1});
                    it = wordSet.erase(it);
                } else {
                    it++;
                }
            }
        }
        return 0;
    }
};
