class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
                int count=0;
        vector<bool> isSorted(strs.size()-1, false);

        for (int i=0; i<strs[0].size(); i++) {
            bool bad = false;

            for (int j=0; j<strs.size()-1; j++) {

                if (!isSorted[j] && strs[j][i] > strs[j+1][i]) {
                    count++;
                    bad = true;
                    break;

                } 
            }
            if (bad) continue;
            for (int j = 0; j < strs.size() - 1; j++) {
                if (strs[j][i] < strs[j + 1][i])
                    isSorted[j] = true;
            }

        }

        return count;
    }
};
