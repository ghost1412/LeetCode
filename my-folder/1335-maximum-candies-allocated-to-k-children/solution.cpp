class Solution {
public:

    bool canGiveCandy(vector<int>& candies, long long k, int candySize) {
        long long countOfCandy = 0;
        for(int i=0; i<candies.size(); i++) {
            countOfCandy += candies[i]/candySize;
        }
        return countOfCandy >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = 10000000, mid = 0, ans;
        while (l<=r) {
            mid = l + (r-l)/2;
            if (canGiveCandy(candies, k, mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return r;
    }
};
