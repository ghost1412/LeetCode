class Solution {
public:

    int calculateMid(int first, int last) {
        return first + (last - first)/2;
    }

    int search(vector<int>& nums, int target) {
        
        int first = 0, last = nums.size() - 1;
        int mid = this->calculateMid(first, last);

        while (first <= last) {
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[first]) {
                if (nums[mid] >= target && nums[first] <= target) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            } else {
                if (nums[mid] <= target && nums[last] >= target) {
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
            mid = this->calculateMid(first, last);
        }
        return -1;
    }
};
