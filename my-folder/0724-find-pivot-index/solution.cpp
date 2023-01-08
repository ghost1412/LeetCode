class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());

        left[0]=0;
        right[nums.size()-1]=0;
        
        for(int i=1;i<nums.size();i++)
            left[i]=nums[i-1]+left[i-1];
            
        for(int i=nums.size()-2;i>=0;i--)
            right[i]=right[i+1]+nums[i+1];
            
        for(int i=0;i<nums.size();i++){
            if(right[i]==left[i]) return i;
        }
        return -1;
    }
};
