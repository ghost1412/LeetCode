class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int in = nums.size() - 1;
        if(in == 0) return;
        if(in == 1){
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return;
        }
        bool flag = false;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i-1]<nums[i]){
                in = i;
                flag = true;
                break;
            }
        }
        cout<<in;
        int jbig = INT_MAX, jbigi;
        for(int i=in-1; i<nums.size(); i++){
            if(nums[i] > nums[in-1] && jbig >= nums[i] && flag){
                cout<<i;
                jbig = nums[i];
                jbigi = i;
            }
        }
        //cout<<jbig;
        if(flag){
            int temp = nums[jbigi];
            nums[jbigi] = nums[in-1];
            nums[in-1] = temp;
        }
        if(!flag) in=0;
        in--;
        reverse(nums.begin()+in+1, nums.end());

    }
};
