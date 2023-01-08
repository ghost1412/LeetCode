class Solution {
public:

    int binarySearchInsert(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return l;
        }
        int mid = l + (r - l)/2;
        if (nums[mid] == target) return mid;
        else if(nums[mid] > target) {
            return binarySearchInsert(nums, target, l, mid-1);
        } else {
            return binarySearchInsert(nums, target, mid+1, r);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return binarySearchInsert(nums, target, 0, nums.size() - 1);
    }
};
