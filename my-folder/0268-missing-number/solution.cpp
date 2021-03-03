class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums[0]^0, n = nums.size();
        for(int i=1; i<n; i++){
            x = x^nums[i]^i;
        }
        return x^n;
    }
};
