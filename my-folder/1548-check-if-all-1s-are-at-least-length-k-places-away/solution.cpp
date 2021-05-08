class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lasti = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(lasti == INT_MAX)
                    lasti = i;
                else if(i - lasti <= k)
                    return 0;
                else
                    lasti = i;
            }
        }
        return 1;
    }
};
