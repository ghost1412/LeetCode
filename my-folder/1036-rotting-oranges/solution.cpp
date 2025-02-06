class Solution {
public:

    bool isValid(int x, int y, int m, int n) {
        return (x>=0 && x<m && y>= 0 && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        pair<int, int> top;
        int x, y;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (int i=0; i<dir.size(); i++) {
                x=top.first+dir[i].first;
                y=top.second+dir[i].second;
                if (isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] == 1) {
                    grid[x][y] = 1 + grid[top.first][top.second];
                    q.push({x, y});
                }
            }
        }
        int ans = 2;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 1) return -1;
                ans = max(ans, grid[i][j]);
            }
        }
        return ans-2;
    }
};

