class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int max_i = 0;
        for(int i=1; i<n; i++){
            if(dp[i] > dp[max_i])
                max_i = i;
        }
        int temp = nums[max_i];
        int count = dp[max_i];
        vector<int> ans;
        for(int i=max_i; i>=0; i--){
            if(temp%nums[i] == 0 && dp[i] == count){
                ans.push_back(nums[i]);
                count--;
                temp = nums[i];
            }
        }
        return ans;
    }
};
