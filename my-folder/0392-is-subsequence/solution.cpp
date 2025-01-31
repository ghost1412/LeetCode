class Solution {
public:

    bool isSubsequence(string s, string t) {
        int i=0, j=0, n=t.size(), m=s.size();

        while (j<n && i<m) {
            if (s[i] != t[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return (i==m);
    }
};
