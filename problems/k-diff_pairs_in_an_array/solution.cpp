class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(k!=0){
                if(mp.find(nums[i])!=mp.end()) continue;
                if(mp.find(nums[i]+k)!=mp.end()) count++;
                if(mp.find(nums[i]-k)!=mp.end()) count++;
                mp[nums[i]]++;
            }else{
                mp[nums[i]]++;
                if(mp[nums[i]] == 2) count++;
            }
            
        }
        return count;
    }
};