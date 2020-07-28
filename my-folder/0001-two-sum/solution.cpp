class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=1, flag=0;
        for(i=0; i<nums.size()-1; i++){
            for(j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    cout<<i<<j;
                    flag = 1;
                    break;
                }
            }
            if(flag==1) break;
        }
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
};
