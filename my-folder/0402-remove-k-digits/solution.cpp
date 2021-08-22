class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        int c = 0;
        for(auto& i:num){
            while(!s.empty() && s.back() > i && c<k){
                s.pop_back();
                c++;
            }
            s += i;
        }
        s.resize(num.size() - k);
        bool lead = true;
        string res = "";
        for(auto& i: s){
            if(lead && i == '0') continue;
            lead = false;
            res += i;
        }
        return res.empty()?"0":res;
    }
};
