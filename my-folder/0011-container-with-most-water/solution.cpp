class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int mArea = 0, area = 0;

        while (i<j) {
            int left = height[i];
            int right = height[j];
            area = (j-i) * min(left, right);
            mArea = max(mArea, area);

            if (left < right) i++;
            else if (right <= left) j--;
        }
        return mArea;
    }
};
