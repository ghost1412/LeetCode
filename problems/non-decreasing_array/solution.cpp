class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0, min_valid = INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(count>=1) return false;
                count++;
                if(nums[i+1] < min_valid)
                    nums[i+1] = nums[i];
            }else{
                min_valid = nums[i];
            }
        }
        return true;
    }
};