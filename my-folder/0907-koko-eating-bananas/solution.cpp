class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=1000000000;
        int mid = left + (right-left)/2;

        while (left<=right) {
            mid = left + (right-left)/2;
            if (canEatInTime(piles, h, mid)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }

    bool canEatInTime(vector<int>& piles, int h, int k) {
        long long hour = 0;
        for (int i=0; i<piles.size(); i++) {
            hour += piles[i]/k;
            if (piles[i]%k != 0) hour++;
        }
        return hour<=h;
    }
};
