class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(int i=0; i<t.size(); i++){
            if(i<s.size())
                x ^= s[i];
            x ^= t[i];
        }
        return (char)x;
    }
};