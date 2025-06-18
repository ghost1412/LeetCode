class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        int dir = 1;
        vector<string> rows(numRows);
        int currRow = 0;
        for (int i=0; i<s.size(); i++) {
            rows[currRow] += s[i];
            if (currRow==0) dir=1;
            else if (currRow==numRows-1) dir=-1;
            currRow+=dir;
        }

        string result;
        for (string& row : rows)
            result += row;

        return result;
    }
};
