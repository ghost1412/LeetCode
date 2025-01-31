class Solution {
public:

    bool isClosingBracket(char c) {
        return (c==')' || c==']' || c=='}');
    }

    bool isCorrectOpposite(char c, char d) {
        if (c == ')') return (d == '(');
        if (c == ']') return (d == '[');
        if (c == '}') return (d == '{');
        return false;
    }

    bool isValid(string s) {
        stack<char> st;

        for (int i=0; i<s.size(); i++) {
            if (isClosingBracket(s[i])) {
                if (st.empty() || !isCorrectOpposite(s[i], st.top())) return false;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
