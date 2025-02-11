class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2], curr_sum = 0;
        int left = 0, right = nums.size();
        for (int i=0; i<nums.size()-2; ++i) {
            int curr = nums[i];
            left = i+1;
            right = nums.size()-1;
            while (left < right) {
                curr_sum = nums[i] + nums[left] + nums[right];
                if (curr_sum == target) return target;
                if (abs(target-curr_sum) < abs(target - sum)) {
                    sum = curr_sum;
                }
                if (curr_sum > target) {
                   right--;
                } else {
                    left++;
                }

            }
        }
        return sum;
    }
};
