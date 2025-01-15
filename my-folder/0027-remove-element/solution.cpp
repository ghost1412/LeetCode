class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0, right=nums.size()-1;

        while(left <= right) {
            if (nums[left] != val) {
                left++;
            } else if (nums[right] == val) {
                right--;
            } else {
                nums[left] = nums[right];
                nums[right] = val;
                right--;
                left++;
            }
        }
        return left;
    }
};
