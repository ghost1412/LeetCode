class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0, j=0, sum=0, ans= INT_MAX;
        int left=0;
        for(i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum>=s){
                ans = min(ans, i+1-left);
                sum-=nums[left++];
            }
        }
        return (ans!=INT_MAX) ? ans:0;
    }
};