class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> a(n+1,0);
       // if(s[0] == '0') return 0;
        a[0] = 1;
        a[1]=s[0]=='0'?0:1;
        for(int i=2; i<=s.size(); i++){
            int first = stoi(s.substr(i-1,1));
            int sec = stoi(s.substr(i-2, 2));
            if(first>=1 && first<=9) a[i]+=a[i-1];
            if(sec>=10 && sec<=26) a[i]+=a[i-2];
        }
        return a[n];
    }
};
