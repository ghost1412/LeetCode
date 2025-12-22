class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unordered_map<int, int>mp;
        int count=0;

        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                mp[nums[i]+nums[j]]++;
            }

            for (int k=i+2; k<nums.size(); k++) {
                count+=mp[nums[k]-nums[i+1]];
            }
        }


        return count;
    }
};
