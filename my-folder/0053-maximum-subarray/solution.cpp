class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxFinal = INT_MIN, currMax = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] + currMax < nums[i]) {
                currMax = nums[i];
            } else {
                currMax = nums[i] + currMax;
            }
            maxFinal = max(maxFinal, currMax);
        }
        return maxFinal;
    }
};
