class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> a(101, 0);
        int unique = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (a[nums[i]] == 0 && nums[i] != 0) unique++;
            a[nums[i]]++;
        }
        return unique;
    }
};
