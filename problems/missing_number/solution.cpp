class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0; i<=nums.size(); i++){
            x ^= i;
            if(i < nums.size())
                x ^= nums[i];
        }
        return x;
    }
};