class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int i=0; i<nums2.size(); i++) mp[nums2[i]] = i;
        vector<int> ans;
        for(int i=0; i< nums1.size(); i++) {
            int index = mp[nums1[i]];
            int isPresent = 0;
            for (int j=index; j<nums2.size(); j++) {
                if (nums1[i] < nums2[j]) {
                    ans.push_back(nums2[j]);
                    isPresent = 1;
                    break;
                }
            }
            if (!isPresent) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
