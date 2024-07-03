class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        for(int i=s.length()-1; i>=0; i--){
            if (!len && s[i] == ' ') {
                continue;
            } else if(len && s[i] == ' ') {
                return len;
            } else {
                len++;
            }
        }
        return len;
    }
};
