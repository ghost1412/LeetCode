class Solution {
public:

    pair<int, int> kadaneMinMax(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;
        for (int i=0; i<nums.size(); i++) {
            currMin = min(currMin+nums[i], nums[i]);
            currMax = max(currMax+nums[i], nums[i]);
            maxSum = max(currMax, maxSum);
            minSum = min(currMin, minSum);
        }
        return {minSum, maxSum};
    }

    int maxAbsoluteSum(vector<int>& nums) {
        auto minMax = kadaneMinMax(nums);
        return max(minMax.second, abs(minMax.first));
    }
};
