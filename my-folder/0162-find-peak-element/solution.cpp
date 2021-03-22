class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = (nums[0] > nums[n-1])?0:n-1;
        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[i-1] && nums[i] > nums[i+1])
                ans = (nums[ans] > nums[i]) ? ans:i;
        }
        return ans;
    }
};
