class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int[3]> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]][0] = 1;
                mp[nums[i]][1] = i;
                mp[nums[i]][2] = i;
            }else{
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
        }
        int len = INT_MAX, degree = 0;
        for(auto iter=mp.begin(); iter!=mp.end(); iter++){
            if(iter->second[0] > degree){
                degree = iter->second[0];
                len = iter->second[2] - iter->second[1] + 1;
            }else if(iter->second[0] == degree){
                len = min(len, iter->second[2]-iter->second[1]+1);
            }
        }
        return len;
    }
};