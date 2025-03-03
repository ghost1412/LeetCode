class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        obstacleGrid[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) continue;
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                } 

                int up = (i>0) ? obstacleGrid[i-1][j] : 0;
                int left = (j>0) ? obstacleGrid[i][j-1] : 0;
                obstacleGrid[i][j] = up+left;
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
