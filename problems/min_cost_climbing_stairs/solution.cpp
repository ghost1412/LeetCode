class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int temp[n];
        temp[0] = cost[0];
        temp[1] = cost[1];
        for(int i=2; i<n; i++){
            temp[i] = cost[i] + min(temp[i-1], temp[i-2]);
        }
        return min(temp[n-1], temp[n-2]);
    }
};