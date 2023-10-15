class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string outputS = "";
        int firstSLen = word1.length();
        int secondSLen = word2.length();

        int maxLen = max(firstSLen, secondSLen);
        for (int i=0; i< maxLen; i++) {
            if (i < firstSLen) {
                outputS += word1[i];
            }
            if (i < secondSLen) {
                outputS += word2[i];
            }
        }
        return outputS;
    }
};
