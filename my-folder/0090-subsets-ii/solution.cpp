class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // vector<vector<int>> res;
        // int n = nums.size();

        // for (int mask =0; mask< (1<<n); mask++) {
        //     vector<int> subset;
        //     for(int i=0; i<nums.size(); i++) {
        //         if (mask & 1 << i) {
        //             subset.push_back(nums[i]);
        //         }
        //     }
        //     res.push_back(subset);
        // }
        // return res;
        int start = 0, end=0;
        vector<vector<int>> res;
        res.push_back({});
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            start = (i > 0 && nums[i] == nums[i - 1]) ? end : 0;
            end = res.size();
            for (int j=start; j<end; j++) {
                vector<int> temp(res[j]);
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
