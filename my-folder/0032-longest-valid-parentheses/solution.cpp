class Solution {
public:
    int longestValidParentheses(string s) {
        int maxl = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    maxl = max(maxl, i-st.top());
            }
        }
        return maxl;
    }
};
