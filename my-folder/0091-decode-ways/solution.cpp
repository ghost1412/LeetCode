class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for (int i=2; i<s.size()+1; i++) {
            int doub = stoi(s.substr(i-2, 2));
            int sing = stoi(s.substr(i-1, 1));

            if (doub >= 10 && doub <= 26) {
                dp[i] = dp[i-2];
            }

            if (sing >= 1 && sing <= 9) {
                dp[i] += dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
