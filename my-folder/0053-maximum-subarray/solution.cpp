class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, temp = 0;
        for(int i=0; i<nums.size(); i++){
            if(temp + nums[i] < nums[i])
                temp = nums[i];
            else
                temp += nums[i];
            ans = max(temp, ans);
        }
        return ans;
    }
};
