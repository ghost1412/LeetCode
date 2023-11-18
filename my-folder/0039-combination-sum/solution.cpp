class Solution {
public:



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combos;
        vector<int> combination;
        int index = 0;
        return combinationSum(candidates, target, combos, index, combination);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target, vector<vector<int>>& combos, int index, vector<int>& combination) {
        
        if (target == 0) {
            combos.push_back(combination);
            return combos;
        }
 
        for (; index<candidates.size(); index++) {
            int val = candidates[index];
            if (target - val < 0) return combos;

            combination.push_back(val);
            combinationSum(candidates, target-val, combos, index, combination);
            combination.erase(combination.end()-1);
        }
        return combos;
    }
};
