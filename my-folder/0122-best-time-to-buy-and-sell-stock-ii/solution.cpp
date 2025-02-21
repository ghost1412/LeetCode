class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mProfit = 0;
        int currShare = prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                mProfit += (prices[i]-prices[i-1]);
            }
        }
        return mProfit;
    }
};
