class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string, bool> mp;
       for (int i=0; i<wordDict.size(); i++){
          mp[wordDict[i]] = true;
       }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        string subStr = "";
       for (int i=1; i<s.size()+1; i++) {
            for (int j=0; j<=i; j++) {
                subStr = s.substr(j, i-j);
                if (dp[j] && mp.find(subStr) != mp.end()) {
                    dp[i] = true;
                }
            }
       }
       return dp[s.size()];
    }
};
