class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int>> s;
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    s.push({i, j});
                    while (!s.empty()) {
                        pair<int, int> top = s.top();
                        s.pop();
                        int a = top.first;
                        int b = top.second;
                        if(a<0 || a>=m || b<0 || b>=n || grid[a][b] == '0') continue;
                        grid[a][b] = '0';
                        s.push({a+1, b});
                        s.push({a-1, b});
                        s.push({a, b+1});
                        s.push({a, b-1});
                    }
                }
            }
        }
        return ans;
    }
};
