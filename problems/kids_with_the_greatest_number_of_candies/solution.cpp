class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int max1 = INT_MIN;
        for(int i=0; i<candies.size(); i++){
            max1 = max(candies[i], max1);
        }
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies >= max1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};