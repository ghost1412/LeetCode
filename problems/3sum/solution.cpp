class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (i!=0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    ans.push_back(trip);
                    int left = nums[j];
                    int right = nums[k];
                    while (j < k && nums[j] == left) {
                        j++;
                    }
                    while (j < k && nums[k] == right) {
                        k--;
                    }
                } else if (nums[i] + nums[j] + nums[k] > 0){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};