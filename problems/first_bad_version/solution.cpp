// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int min = 1, max = n;
        while(min < max){
            int mid = min + (max-min)/2;
            if(isBadVersion(mid)) max = mid;
            else min = mid+1;
        }
        return min;
    }
};