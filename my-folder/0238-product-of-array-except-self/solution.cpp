class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix(sz, 1);
        int product = 1;
        for (int i=1; i<sz; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int suffix = nums[sz-1];
        for (int i=sz-2; i>=0; i--) {
           prefix[i] *= suffix;
           suffix *= nums[i];
        }
        return prefix;

    }
};
