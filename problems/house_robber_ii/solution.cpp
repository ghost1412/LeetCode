class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));
        vector<int> dp(n+2, 0);  
        vector<int> dp1(n+2, 0);
        for(int i=0; i<n; i++){
            if(i>0)
                dp[i+2] = max(dp[i]+nums[i], dp[i+1]);
            dp1[i+2] = max(dp1[i]+nums[i], dp1[i+1]);
        }
        return max(dp[n+1], dp1[n]);
    }
};
