class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int maj = nums[0];
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == maj) count++;
            else count--;
            if(count<=0){
                maj = nums[i];
                count = 1;
            }
                    cout<<count;

        }
        return maj;
    }
};
