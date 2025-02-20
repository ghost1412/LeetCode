class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());
        mergedIntervals.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (mergedIntervals.back()[1] < intervals[i][0]) {
                mergedIntervals.push_back(intervals[i]);
            } else
            if (mergedIntervals.back()[1] < intervals[i][1]) {
                mergedIntervals.back()[1] = intervals[i][1];
            }  
        }
        return mergedIntervals;
    }
};
