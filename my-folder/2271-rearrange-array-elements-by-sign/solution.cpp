class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int negPoint = 0, posiPoint = 0, flip = 0;

        while (negPoint < nums.size() && posiPoint < nums.size()) {
            while (nums[posiPoint] < 0 && posiPoint < nums.size()) posiPoint++;
            if (posiPoint < nums.size()) {
                res.push_back(nums[posiPoint]);
                flip = 1;
                posiPoint++;
            }
            
            while (nums[negPoint] >= 0 && negPoint < nums.size()) negPoint++;
            if (negPoint < nums.size()) {
                res.push_back(nums[negPoint]);  
                flip = -1;
                negPoint++;
            }
            
        }
        return res;
    }
};
