class Solution {
public:
bool detectCycle(vector<vector<char>> &mat, int i, int j, char c){
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            if(mat[x][y] == '#') return true;
            else mat[x][y] = '#';
            for(auto it:d){
                int nx = x + it.first;
                int ny = y + it.second;
                if(nx>=0 && ny >=0 && nx<n && ny<m && mat[nx][ny] == c)
                    q.push({nx, ny});
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != '#'){
                    bool x = detectCycle(mat, i, j, mat[i][j]);
                    if(x) return x;
                }
            }
        }
        return false;
    }
};
