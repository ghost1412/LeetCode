class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> seen(n + 1, false);
        seen[0] = true;
        for (int i=1; i<n+1; i++) {
            for (int j=0; j<=i; j++) {
                string subString = s.substr(j, i-j);
                if (seen[j] && words.find(subString) != words.end()) {                
                    seen[i] = true;
                }
            }
        }
        return seen[n];
    }
};
