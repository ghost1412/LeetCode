class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return {};
        }
        sort(nums.begin(), nums.end());
        for(int k=0; k<nums.size()-2; k++){
            if(k!=0 && nums[k]==nums[k-1]) continue;
            int i=k+1;
            int j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> r;
                    r.push_back(nums[k]);
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    ans.push_back(r);
                    int left = nums[i];
                    int right = nums[j];
                    while(i<j && left==nums[i])
                        i++;
                    while(i<j && right==nums[j])
                        j--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                       j--;
                }
                else
                       i++;
            }
        }
        return ans;
    }
};