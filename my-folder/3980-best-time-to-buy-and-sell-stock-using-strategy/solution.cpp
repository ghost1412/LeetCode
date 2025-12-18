class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<long long> presum;
        int n = prices.size();

        vector<long long> preSumPrices(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSumPrices[i + 1] = preSumPrices[i] + prices[i];
        }

        presum.push_back(prices[0]*strategy[0]);
        for (int i=1; i<n; i++) {
            presum.push_back(presum[i-1]+prices[i]*strategy[i]);
        }

        long long maxSum=presum[prices.size()-1];

        for (int i=0; i+k<=n; i++) {
                long long newSum=preSumPrices[i+k]-preSumPrices[i+k/2];
                long long originalWindow =
                presum[i + k - 1] - (i > 0 ? presum[i - 1] : 0);
                long long totalAfter = presum[n-1]-originalWindow+newSum;
                maxSum = max(maxSum, totalAfter);
        }
        return maxSum;
    }
};
