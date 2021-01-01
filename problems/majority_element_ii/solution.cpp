class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0, count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == a) count1++;
            else if(nums[i] == b) count2++;
            else if(count1 == 0){
                count1++;
                a = nums[i];
            }
            else if(count2 == 0){
                count2++;
                b = nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == a) count1++;
            else if(nums[i] == b) count2++;
        }
        if(count1>nums.size()/3) ans.push_back(a);
        if(count2>nums.size()/3) ans.push_back(b);
        return ans;
    }
};