class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, great, same;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == pivot) {
                same.push_back(nums[i]);
            } else if (nums[i] < pivot) {
                less.push_back(nums[i]);
            } else {
                great.push_back(nums[i]);
            }
        }
        for (int i=0; i<same.size(); i++) {
            less.push_back(same[i]);
        }
        for (int i=0; i<great.size(); i++) {
            less.push_back(great[i]);
        }
        return less;
    }
};
