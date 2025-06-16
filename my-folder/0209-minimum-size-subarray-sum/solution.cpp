class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0; int r=0; int sum=0; int minLen = INT_MAX;

        for (r=0; r<nums.size(); r++) {
            sum += nums[r];

            if (sum==target) {
                minLen = min(minLen, r-l+1);
            }

            while (sum > target) {
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
                if (sum >=target) {
                    minLen = min(minLen, r-l+1);
                }
            }
        }
        return (minLen==INT_MAX) ? 0 : minLen;
    }
};
