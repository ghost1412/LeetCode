class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_map<char, int> mp;

        int left=0;
        for (int right=0; right<s.size(); right++) {
            mp[s[right]]++;
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            } 
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
