class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            left[i] = left[i-1]*nums[i-1];
        }
        int suffix_prod = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            if(i != nums.size()-1) {
                left[i] *= suffix_prod;   
            }
            suffix_prod *= nums[i];
        }
        return left;
    }
};