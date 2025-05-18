class Solution {
public:

   static bool compareByEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compareByEnd);
        int end  = points[0][1];
        int arrowCount = 1;
        for (int i=1; i<points.size(); i++) {
            if (points[i][0] > end ) {
                arrowCount++;
                end  = points[i][1];
            }
        }
        return arrowCount;
    }
};
