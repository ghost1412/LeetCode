class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0;
        int r = nums.size() - 1;
        int i = nums.size() - 1;
        while(l<=r){
            int lv = pow(nums[l], 2);
            int rv = pow(nums[r], 2);
            if(lv<rv){
                ans[i] = rv;
                r--;
            }else{
                ans[i] = lv;
                l++;
            }
            i--;
        }
        return ans;
    }
};