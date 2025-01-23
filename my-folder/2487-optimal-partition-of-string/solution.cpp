class Solution {
public:
    int partitionString(string s) {
        int partCount = 1;
        string currSubString = string(1, s[0]);
        for(int i=1; i<s.size(); i++) {
            if (currSubString.find(s[i]) != string::npos) {
                currSubString = string(1, s[i]);
                partCount++;
            } else {
                currSubString += s[i];
            }
        }
        return partCount;
    }
};
