class Solution {
public:

    bool hasOneDiff(string a, string b) {
        int diff = 0;
        for (int i=0; i<a.size(); i++) {
            if(a[i] != b[i]) diff++;
        }

        return (diff==1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sort(wordList.begin(), wordList.end());
        unordered_set<string> s(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [top, level] = q.front();
            q.pop();

            for (auto it=s.begin(); it!=s.end();) {
                string nextWord = *it;
                if (hasOneDiff(top, nextWord)) {
                    if (nextWord == endWord) return level+1;
                    q.push({nextWord, level+1});
                    it = s.erase(it);
                } else {
                    it++;
                }
            }
        }
        return 0;
    }
};
