// The API isBadVersion is defined for you.
// bool isBadVersion(int version);



class Solution {
public:

    int isBadVersionBinarySearch(int l, int r) {
        int mid = l + (r-l) /2 ;
        bool isBadCurrent = isBadVersion(mid);
        bool isBadPrev = isBadVersion(mid-1);
        if (isBadCurrent && !isBadPrev) return mid;
        if (isBadCurrent && isBadPrev) {
            return isBadVersionBinarySearch(l, mid - 1);
        } else {
            return isBadVersionBinarySearch(mid + 1, r);
        }

    }

    int firstBadVersion(int n) {
        return isBadVersionBinarySearch(0, n);
    }
};
