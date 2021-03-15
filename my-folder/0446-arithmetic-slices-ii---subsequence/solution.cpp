#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<LL, int>> dp(n);
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                LL diff = (LL)A[i] - (LL)A[j];
                int count = 0;
                if(dp[j].find(diff)!=dp[j].end())    //upto j diff valued difference arthmetic subarrays
                    count = dp[j][diff];
                dp[i][diff] += count + 1;
                ans += count;
            }
        }
        return (int)ans;
    }
};
