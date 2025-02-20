class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int, int>> s;
        vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        int maxArea = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows ; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int currArea = 1;
                    s.push({i, j});
                    grid[i][j] = 2;
                    while (!s.empty()) {
                        auto top = s.top();
                        s.pop();
                        for (int i=0; i<4; i++) {
                            int x = top.first+dir[i].first;
                            int y = top.second + dir[i].second;

                            if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                                s.push({x, y});
                                currArea++;
                                grid[x][y] = 2;
                            }
                        }
                    }
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
