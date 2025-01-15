class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        int sz = nums.size()-1;
        int left=(nums[0]);
        int cont = false;
        for (int i=0; i<sz; i++) {
            if (nums[i]+1 == nums[i+1]) {
                cont = true;
                continue;
            } else {
                if (left == nums[i]) {
                    ans.push_back(to_string(nums[i]));
                } else {
                    ans.push_back(to_string(left)+"->"+to_string(nums[i]));
                }
                cont = false;
                left=nums[i+1];
            }   
        }
        if (cont) {
            ans.push_back(to_string(left)+"->"+to_string(nums[sz]));
        } else {
            ans.push_back(to_string(nums[sz]));
        }
        return ans;
    }
};
