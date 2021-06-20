class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        if(r == 0) return 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid==0 && nums[mid]>nums[mid+1]) return mid;
            if(mid==n-1 && nums[mid] > nums[mid-1]) return mid;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            else if(nums[mid+1]>nums[mid]) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};