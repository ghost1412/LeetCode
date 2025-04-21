class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size()+1, vector<int>(text2.size()+1, 0));

        for (int i=1; i<text1.size()+1; i++) {
            for (int j=1; j<text2.size()+1; j++) {
                if (text1[i-1] == text2[j-1]) {
                    v[i][j] = v[i-1][j-1] + 1;
                } else {
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[text1.size()][text2.size()];
    }

    int minDistance(string word1, string word2) {
        int lca = longestCommonSubsequence(word1, word2);
        return word1.size()-lca+word2.size()-lca;
    }
};
