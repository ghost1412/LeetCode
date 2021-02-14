class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag = 0, flag2 = 0;
        if(word[0] > 90)
            flag = 1;
        if(word.length()>=2)
            if(word[1]<=90)
                flag2 = 1;
        if(word.length()==1)
            return true;
        cout<<flag2;
        for(int i=1; i<word.size(); i++){
            cout<<i;
            if(word[i]<=90 && flag == 1)
                return false;
            if(flag2 == 1 && word[i] > 90)
                return false;
            if(flag2 == 0 && word[i] <= 90)
                return false;
        }
        return true;
    }
};