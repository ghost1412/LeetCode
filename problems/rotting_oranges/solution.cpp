class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>= n)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = curr.first + dir[i].first;
                int y = curr.second + dir[i].second;
                if(isValid(x, y, m, n) && grid[x][y] == 1){
                    q.push({x, y});
                    grid[x][y] = 1 + grid[curr.first][curr.second];
                }
                    
            }
        }
        int ans = 2;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
                ans = max(ans, grid[i][j]);
            }
        }
        return ans-2;
    }
};