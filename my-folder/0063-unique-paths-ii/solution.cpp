class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 1){
                    a[i][j] = -1;
                    continue;
                }
                else if(a[0][0] == -1) return 0;
                else if(a[0][0] == 0) a[0][0] = 1;
                else if(i == 0 && j!=0)
                    a[i][j] = a[i][j-1];
                else if(i !=0 && j==0)
                    a[i][j] = a[i-1][j];
                else{
                    int up = 0, left = 0;
                    if(a[i-1][j] != -1)
                        up = a[i-1][j];
                    if(a[i][j-1] != -1)
                        left = a[i][j-1];
                    a[i][j] = up + left;
                }
            }
        }        
        if(a[m-1][n-1] == -1) return 0;
        return a[m-1][n-1];
    }
};
