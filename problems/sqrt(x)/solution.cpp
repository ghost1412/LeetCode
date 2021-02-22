class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int left = 1;
        int right = x;
        while(left < right){
            int mid = left + float((right-left)/2);
            if(x/mid == mid) return mid;
            if(x/mid > mid) left = mid+1;
            if(x/mid < mid) right = mid;
            //cout<<left<<right<<" ";
        }
        return left-1;
    }
};