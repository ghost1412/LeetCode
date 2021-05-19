class Solution {
public:
    // bool isValidParentheis(string s){
    //     stack<char> st;
    //     if(s.length() == 0) return 1;
    //     st.push(s[0]);
    //     int i = 1;
    //     while(!st.empty()&&i<s.length()){
    //         char top = st.top();
    //         if(top == '(' && s[i] == ')'){
    //             st.pop();
    //         }else{
    //             st.push(s[i]);
    //         }
    //         i++;
    //     }
    //     if(i == s.length() - 1 && st.empty()) return true;
    //     return false;
    // }
    string removeOuterParentheses(string s) {
        ///return isValidParentheis(s.substr(1, s.length() - 2))? s.substr(1, s.length() - 2):s; 
        int count = 0;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' && count == 0)
                count++;
            else if(s[i] == ')' && count == 1)
                count--;
            else{
                if(s[i] == '(') count++;
                else if(s[i] == ')') count--;

                ans =  ans + s[i];
            }
        }
        return ans;
    }
};