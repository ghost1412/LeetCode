class Solution {
public:
    int numSplits(string s) {
        int ld = 0, rd = 0;
        vector<int> c(26), d(26);
        for(int i=0; i<s.size(); i++){
            if(c[s[i] - 'a'] == 0) rd++;
            c[s[i]-'a']++;
        }
        int count = 0;
        for(int i=0; i<s.size(); i++){
            c[s[i] - 'a']--;
            if(c[s[i] - 'a'] == 0) rd--;
            if(d[s[i] - 'a'] == 0) ld++;
            d[s[i] - 'a']++;
            if(rd == ld) count++;
        }
        return count;
    }
};
