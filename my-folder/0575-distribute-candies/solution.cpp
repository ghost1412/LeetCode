class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = unordered_set<int> (candyType.begin(), candyType.end()).size();
        return n > candyType.size()/2? candyType.size()/2 : n;
    }
};
