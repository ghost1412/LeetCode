class Solution {
public:
    int balancedStringSplit(string s) {
        int x = 0, count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'L') x++;
            if(s[i] == 'R') x--;
            if(!x) count++;
        }
        return count;
    }
};