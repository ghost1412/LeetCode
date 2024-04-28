class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int i = 0;
        for (auto s1: strs[0]) {
            for (auto s2: strs) {
                if (s2[i] != s1) {
                    return s;
                }
            }
            s = s + s1;
            i++;
        }
        return s;

    }
};
