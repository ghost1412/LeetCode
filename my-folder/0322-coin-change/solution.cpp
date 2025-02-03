class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j< coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], 1+dp[i - coins[j]]);
                }
            }
        }
        return (dp[amount] > amount)? -1: dp[amount];
    }
};

/*
    1 2 3 4 5 6 7 8 9 10 11
1
2
5
[1, 2, 4, 5, 6, 7, 8 ,9, 10, 11]
*/
