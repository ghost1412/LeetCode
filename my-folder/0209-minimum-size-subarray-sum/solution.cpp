class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left = 0;
        int minLen = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                minLen = min(minLen, i-left+1);
                sum -= nums[left++];
            }
        }
        return (minLen != INT_MAX) ? minLen:0;
    }
};
