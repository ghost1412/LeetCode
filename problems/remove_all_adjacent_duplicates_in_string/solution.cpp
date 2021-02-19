class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> c;
        for(int i=0; i<S.size(); i++){
            if(c.empty())
                c.push(S[i]);
            else{
                char top = c.top();
                if(top == S[i])
                    c.pop();
                else
                    c.push(S[i]);
            }
        }
        string ans = "";
        while(!c.empty()){
            char top = c.top();
            c.pop();
            ans += top;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};