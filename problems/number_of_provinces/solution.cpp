class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, int node,unordered_set<int>& visited){
        visited.insert(node);
        for(int i=0; i<graph[node].size(); i++){
            if(!visited.count(graph[node][i]))
                dfs(graph, graph[node][i], visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(i!=j && isConnected[i][j] == 1)
                    graph[i].push_back(j);
            }
        }
        int provinces = 0;
        unordered_set<int> visited;
        for(int i=0; i< isConnected.size(); i++){
            if(!visited.count(i)){
                dfs(graph, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
};