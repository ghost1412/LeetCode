class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[i].size(); j++){
                if(i==0 && j==0) continue;
                else if(i==0)
                    a[i][j] += a[i][j-1];
                else if(j==0)
                    a[i][j] += a[i-1][j];
                else
                    a[i][j] += min(a[i][j-1], a[i-1][j]);
            }
        }
        return a[a.size()-1][a[0].size()-1];
    }
};
