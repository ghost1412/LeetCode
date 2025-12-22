class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);

        int best = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<i; j++) {
                bool good = true;

                for (int k=0; k<n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            best = max(best, dp[i]);
        }
        return m-best;
    }

};
