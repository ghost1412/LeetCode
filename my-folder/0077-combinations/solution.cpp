class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> currCombination;


        findCombination(combinations, currCombination, n, k, 1);
        return combinations;
    }

    void findCombination(vector<vector<int>>& combinations, vector<int>& currCombination, int n, int k, int i) {
        
        if (currCombination.size() == k) {
            combinations.push_back(currCombination);
            return;
        }

        for (; i<=n;) {
            currCombination.push_back(i);
            findCombination(combinations, currCombination, n, k, ++i);
            currCombination.erase(currCombination.end()-1);
        }
        return;
    }
};
