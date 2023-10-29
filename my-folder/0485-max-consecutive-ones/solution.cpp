class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak = 0;
        int largestStreak = 0;
        for (int i = 0; i< nums.size(); i++) {
            int n = nums[i];
            if (n == 1) {
                streak += 1;
                largestStreak = max(largestStreak, streak);
            } else {
                streak = 0;
            }
        }
        return largestStreak;
    }
};
