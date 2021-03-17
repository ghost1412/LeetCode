class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1, mp2;
        for(auto i : nums1)
            mp1[i]++;
        for(auto j: nums2)
            mp2[j]++;
        vector<int> ans;
        for(auto i : mp1){
            if(mp2.find(i.first) != mp2.end()){
                int temp = min(i.second, mp2[i.first]);
                    ans.push_back(i.first);
            }
        }
        return ans;
    }
};