class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles;

        for (auto num: nums) {
            auto it = lower_bound(piles.begin(), piles.end(), num);
            if (it == piles.end()) {
                piles.push_back(num);
            } else {
                *it = num;
            }
        }
        return piles.size();
    }

};
