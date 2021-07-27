class Solution {
    private:
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool isValid(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(), vector<int> (mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(auto d: dir){
                pair<int, int> n = {curr.first + d[0], curr.second + d[1]};
                if(isValid(n.first, n.second, mat.size(), mat[0].size())){
                    if(visited[n.first][n.second] == INT_MAX){
                        q.push({n.first, n.second});
                        visited[n.first][n.second] = visited[curr.first][curr.second] + 1;
                    }    
                }
            }
        }
        return visited;
        
    }
};