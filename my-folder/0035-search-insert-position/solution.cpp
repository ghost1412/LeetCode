class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
int loc=0 ;
int i=0;

    for( ;i<nums.size();i++)
    {
        if (nums[i]==target || nums[i]>target)
        {
            loc=i;
            break;
        }    
    }
    if(i==nums.size()){loc=i;}
    return loc;
}

};
