class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = INT_MIN;
        for(int i=0; i<accounts.size(); i++){
            int s = 0;
            for(int j=0; j<accounts[i].size(); j++){
                s += accounts[i][j];
            }
            sum = max(s, sum);
        }
        return sum;
    }
};
