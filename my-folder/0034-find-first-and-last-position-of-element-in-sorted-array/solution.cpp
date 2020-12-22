class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        if(nums.size()==1&&nums[0]!=target) return {-1, -1};
        int s = 0, e = nums.size()-1;
        while(s<e){
            int m = (s+e)/2;
            if(s+1==e&&nums[s]!=target&&nums[e]!=target){
                s=-1;
                e=-1;
                break;
            }             
            if(nums[s]==target && nums[e]==target)
                break;
            if(nums[m]==target && nums[m+1]==target && nums[m-1]==target){
                if(nums[s]!=target) s++;
                if(nums[e]!=target) e--;
            }else if(nums[m]==target && nums[m+1]!=target)
                e = m;
            else if(nums[m]==target && nums[m-1]!=target)
                s = m;
            else if(nums[m]>target) e=m;
            else if(nums[m]<target && m!=s) s=m;
            else if(nums[m]<target && m==s) s=m+1;
        }
        return {s, e};
    }
};
