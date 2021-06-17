class Solution {
public:
    bool isgood(int n){
        string s = to_string(n);
        string ss = s;
        for(int i=0; i<s.size(); i++){
            if(ss[i] == '0' || ss[i] == '1' || ss[i] == '8')
                continue;
            if(ss[i] == '6') {
                ss[i] = '9';
            } else if(ss[i] == '9') {
                ss[i] = '6';
            } else if(ss[i] == '2') {
                ss[i] = '5';
            } else if(ss[i] == '5') {
                ss[i] = '2';  
            }
            else
                return false;
        }
        return s != ss;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=0; i<=n; i++){
            if(isgood(i)) count++;
        }
        return count;
    }
};
