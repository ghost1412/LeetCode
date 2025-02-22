class Solution {
public:

    bool canAchievePenalty(vector<int>& nums, int maxOperations, int penality) {
        long long operationsUsed = 0;
        for (int i=0; i<nums.size(); i++) {
            operationsUsed += (nums[i]-1)/penality;
        }
        return operationsUsed <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r=*max_element(nums.begin(), nums.end()), mid;

        while (l<=r) {
            mid = l + (r-l)/2;

            if (canAchievePenalty(nums, maxOperations, mid)) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
