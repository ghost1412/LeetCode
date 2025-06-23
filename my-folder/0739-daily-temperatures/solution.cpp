class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size());
        stack<int> s;
           for (int i=0; i<t.size();i++) {
            while (!s.empty() && t[i]>t[s.top()]) {
                res[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
