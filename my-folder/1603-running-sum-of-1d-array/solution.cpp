class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (ans.size() == 0) {
                ans.push_back(nums[i]);
                continue;
            }

            ans.push_back(nums[i] + ans[ans.size() - 1]);
        }
        return ans;
    }
};
