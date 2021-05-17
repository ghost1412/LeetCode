class Solution {
public:
    string shift(string s){
        return s.substr(1, s.length()-1) + s.substr(0, 1);
    }
    bool rotateString(string s, string goal) {
        if(s.length() == 0 && goal.length() == 0) return 1;        
        for(int i=0; i<s.length(); i++){
            s = shift(s);
            if(s == goal)
                return true;
        }
        return false;
    }
};
