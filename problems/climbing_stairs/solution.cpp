class Solution {
public:
    int climbStairs(int n) {
        vector<int> w(n+1, 0);
        w[0] = 1;
        w[1] = 1;
        for(int i=2; i<=n; i++){
            w[i] = w[i-1] + w[i-2];
            cout<<w[i];
        }
        return w[n];
    }
};