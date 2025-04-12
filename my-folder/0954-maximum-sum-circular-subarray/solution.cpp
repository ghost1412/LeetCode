class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum= nums[0], currMax = 0, minSum=  nums[0], currMin = 0;

        for (int & a: nums) {
            currMax = max(currMax+a, a);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+a, a);
            minSum = min(minSum, currMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total-minSum) : maxSum;
    }
};
