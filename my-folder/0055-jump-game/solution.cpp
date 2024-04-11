class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        int maxCanJump = 0;

        for (int i=0; i<nums.size(); i++) {
            if (i <= maxCanJump) {
                maxCanJump = max(maxCanJump, i+nums[i]);
            }
        }
        return maxCanJump >= nums.size()-1;
    }
};
