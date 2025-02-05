class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int a=0, b=0, startIdx = 0, minLen = INT_MAX, have=0, req=0;
        vector<int> sFreq(128, 0), tFreq(128, 0);

        for (int i=0; i<t.size(); i++) {
            if (tFreq[t[i]] == 0) req++;
            tFreq[t[i]]++;
        }

        while (b < s.size()) {
            sFreq[s[b]]++;
            if (sFreq[s[b]] == tFreq[s[b]]) have++;

            while (have == req) {
                if (b-a+1 < minLen) {
                    minLen = b-a+1;
                    startIdx = a;
                }
                sFreq[s[a]]--;
                if(sFreq[s[a]] < tFreq[s[a]]) have--;
                a++;
            }
            b++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
