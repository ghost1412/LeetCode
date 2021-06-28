class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0, prev = -2;
        for(int i=0; i<s.size(); ){
            if (s[i] == 'L'){
                int l_t = 0;
                while(s[i]=='L'){
                    l_t++;
                    i++;
                }
                l = max(l, l_t);
            }           
            if(s[i] == 'A') a++;
            i++;
        }
        return (a<2 && l <= 2)? true:false;
    }
};