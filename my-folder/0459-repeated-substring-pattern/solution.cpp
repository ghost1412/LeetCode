class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string S = s+s;
        string sub = S.substr(1, S.size()-2);
        return sub.find(s) == string::npos ? false:true;
    }
};
