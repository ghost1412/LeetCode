class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int max_i = 0;
        int count = 0;

        for (int i=1; i<n; i++) {
            if (dp[i] > dp[max_i]) {
                max_i = i;
            }
        }

        count = dp[max_i];
        vector<int> res;
        int maxModEle = nums[max_i];
        for (int i=max_i; i>=0; i--) {
            if (maxModEle % nums[i] == 0 && dp[i] == count) {
                count--;
                res.push_back(nums[i]);
                maxModEle = nums[i];
            }
        }

        return res;
    }
};
