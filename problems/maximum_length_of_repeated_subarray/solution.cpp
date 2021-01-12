class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int dp[n+1][m+1];
        int ans = INT_MIN;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(B[j-1] == A[i-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};