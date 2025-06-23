class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        int n=r;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                r = mid; // include mid
            } else {
                l = mid + 1; // exclude mid
            }
        }
        return l;
    }
};
