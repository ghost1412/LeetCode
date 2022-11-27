class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        for (int i=0; i < 2*n - 1; i++) {
            while (!s.empty() && nums[s.top()] < nums[i%n]) {
                ans[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return ans;
    }
};


