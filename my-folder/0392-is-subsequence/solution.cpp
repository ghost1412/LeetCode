class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i!=t.length()&&j!=s.length()){
            //cout<<s[i]<<j<<endl;
            if(s[j]!=t[i])
                i++;
            else{
                j++;
                i++;
            }
        }
        if(j==s.length())
            return true;
        return false;
    }
};
