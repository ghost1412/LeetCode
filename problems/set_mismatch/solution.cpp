class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x1 = nums[0];
        for(int i=1; i<nums.size(); i++)
            x1 = x1^nums[i]^i;
        x1 ^= nums.size();
        int set_bit = x1 & ~(x1-1);
        int a = 0, b = 0, flag = 0;
        for(int i=0; i<nums.size(); i++){
            if(set_bit & nums[i]){
                a ^= nums[i];
            }else
                b ^= nums[i];
            if(set_bit & (i+1))
                a ^= (i+1);
            else
                b ^= (i+1);          
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == a)
                flag = 1;
        if(flag == 1){
            ans.push_back(a);
            ans.push_back(b);
        }else{
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }
};