class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int m1 = INT_MIN, m2= INT_MIN, m3 = INT_MIN;
        bool flag = false;
        for(int i=0; i<nums.size(); i++){
            m1 = max(m1, nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(m1 != nums[i])
                m2 = max(m2, nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=m1 && nums[i]!=m2){
                m3 = max(m3, nums[i]);
                flag = true;   
            }
        }
        return m3!=INT_MIN||flag?m3:m1;
    }
};
