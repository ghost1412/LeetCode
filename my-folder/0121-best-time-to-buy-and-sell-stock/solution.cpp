class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;        
        int maxp = 0, min = prices[0];
        for(int i=1; i<prices.size(); i++){
            maxp = max(maxp, prices[i] - min);
            if(prices[i] < min)
                min = prices[i];
        }
        return maxp;
    }
};
