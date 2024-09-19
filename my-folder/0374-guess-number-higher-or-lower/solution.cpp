/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
     int guessBS(int l, int r) {
        if (l > r) return l;
        int mid = l + (r-l)/2;
        int guessRes = guess(mid);
        if (guessRes == 0) return mid;
        else if (guessRes == -1) return guessBS(0, mid-1);
        else return guessBS(mid+1, r);
    }

    int guessNumber(int n) {
        return guessBS(0, n);
    }
};
