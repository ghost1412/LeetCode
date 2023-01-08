class Solution {
public:
    int binarySearch(vector<int> & nums, int target, int l, int r) {
        if (l > r) return -1;
        int mid = l + (r - l)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarySearch(nums, target, l, mid-1);
        else return binarySearch(nums, target, mid+1, r);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};