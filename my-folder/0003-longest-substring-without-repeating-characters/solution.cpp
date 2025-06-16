class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;

        int len = 0;

        int l=0, r=0;
        for (r=0; r<s.size(); r++) {
            if (mp[s[r]]==true) {
                while (s[l]!=s[r]) {
                    mp[s[l]] = false;
                    l++;
                }
                l++;
                len = max(len, r-l+1);
            } else {
                mp[s[r]] = true;
                len = max(len, r-l+1);
            }
        }
        return len;
    }
};
