class Solution {
public:

    int findFirstNegative(vector<int> &row) {
        int l = 0, r=row.size()-1, mid=-1;
        int ans=-1;
        while (l<=r) {
            mid = l + (r-l)/2;

            if(row[mid] < 0) {
                ans=mid;
                r=mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    } 

    int countNegatives(vector<vector<int>>& grid) {
        

        int count=0;

        for (int i=0; i<grid.size(); i++) {
            int negIdx = findFirstNegative(grid[i]);

            if (negIdx != -1) {
                count += grid[i].size() - negIdx;
            }
        }
        return count;
    }
};
