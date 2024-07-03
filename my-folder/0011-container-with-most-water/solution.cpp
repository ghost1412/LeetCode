class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxA = 0;
        while (r>=l) {
            //cout<<l<<r<<":"<<min(height[l], height[r])*(r-l)<<" ";
            maxA = max(maxA,  min(height[l], height[r])*(r-l));
            if (height[r] >= height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;
    }
};
