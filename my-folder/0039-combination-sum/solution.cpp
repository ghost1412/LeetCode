class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> allCombinations;
        vector<int> currCombination;

        findCombinationSum(candidates, target, 0, allCombinations, currCombination);
        return allCombinations;
    }

    void findCombinationSum(vector<int>& candidates, int target, int index, vector<vector<int>>& allCombinations, vector<int>& currCombination) {
        if (target == 0) {
            allCombinations.push_back(currCombination);
            return;
        }

        for (; index<candidates.size(); index++) {
            int currCandidate = candidates[index];
            if (target < currCandidate) break;
            currCombination.push_back(currCandidate);
            findCombinationSum(candidates, target-currCandidate, index, allCombinations, currCombination);
            currCombination.erase(currCombination.end()-1);
        }
        return;
    }
};
