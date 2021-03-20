class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 1, i3 = 1, i5 = 1;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<n+1; i++){
            dp[i] = min(min(dp[i2]*2, dp[i3]*3), dp[i5]*5);
            if(dp[i]%2 == 0) i2++;
            if(dp[i]%3 == 0) i3++;
            if(dp[i]%5 == 0) i5++;
        }
        return dp[n];
    }
};
