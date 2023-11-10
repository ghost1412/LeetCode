class Solution {
public:
    int trap(vector<int>& height) {
        bool filling = false;
        int area = 0, l = 0, r= height.size() - 1, lmax=INT_MIN, rmax=INT_MIN;
        while (l<r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {
                area += (lmax - height[l++]);
            } else {
                area += (rmax - height[r--]);
            }
        } 
        return area;
    }
};
