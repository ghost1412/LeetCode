class Solution {
public:
    int numDecodings(string s) {
        int  n = s.size() + 1;
        vector<int> dp(n, 0);

        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;

        for (int i=2; i<n; i++) {
            int singleSelection = stoi(s.substr(i-1, 1));
            int doubleSelection = stoi(s.substr(i-2, 2));

            if (singleSelection >= 1 && singleSelection <= 9) {
                dp[i] += dp[i-1];
            }

            if (doubleSelection >= 10 && doubleSelection <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n-1];
    }
};
