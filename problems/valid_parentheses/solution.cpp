class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                c.push(s[i]);
            else{
                if(c.empty()) return false;
                char top = c.top();
                c.pop();
                if(s[i] == ')' && top != '(')
                    return false;
                else if(s[i] == ']' && top != '[')
                    return false;
                else if(s[i] == '}' && top != '{')
                    return false;
            }
        }
        if(c.empty())
            return true;
        return false;
    }
};