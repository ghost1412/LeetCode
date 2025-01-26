class Solution {
public:

    bool isExpression(const string& exp) {
        return (exp == "+" || exp == "-" || exp == "*" || exp == "/");
    }

    int eval(int& a, int& b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return b - a;
        if (op == "*") return a * b;
        if (op == "/") return b / a;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (isExpression(token)) {
                int first = s.top(); s.pop();
                int second = s.top(); s.pop();
                s.push(eval(first, second, token));
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
