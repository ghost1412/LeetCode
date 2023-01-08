class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int count = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != me) count--;
            else count++;
            if (count < 0) {
                 me = nums[i];
                 count = 0;
            }
        }
        return me;
    }
};