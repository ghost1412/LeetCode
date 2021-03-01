class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int swap = 0;
        int diffX = 0, diffY = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i] && s1[i] == 'x')
                diffX++;
            else if(s1[i]!=s2[i])
                diffY++;
        }
        int diff = diffX + diffY;
        if(diff%2 != 0) return -1;
        return (diffX%2 == 0)? (diff/2): diff/2+1;
    }
};
