class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> a(s.length());
        for(int i=0; i<s.length(); i++){
            a[indices[i]] = s[i];
        }
        string ans(a.begin(), a.end());
        return ans;
    }
};