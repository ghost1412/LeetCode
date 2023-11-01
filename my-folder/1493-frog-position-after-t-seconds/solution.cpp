class Solution {
public:


    unordered_map<int, vector<int>> createGraph(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (int i=0; i<edges.size(); i++) {
            int root = edges[i][0];
            int child = edges[i][1];
            if (graph.find(root) == graph.end()) {
                graph[root] = std::vector<int>();
            }
            if (graph.find(child) == graph.end()) {
                graph[child] = std::vector<int>();
            }
            graph[root].push_back(child);
            graph[child].push_back(root);
        }
        return graph;
    }

    double dfsProbablity(unordered_map<int, vector<int>> graph, int target, int current, std::vector<bool>& visited, int time) {

        if (current != 1 && time>=0 && target == current && graph[current].size() == 1) return 1;
        if (current == target && time == 0) return 1;
        if (time <=0) return 0;

        visited[current] = true;

        int size = graph[current].size();

        if (current == 1) size++;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                double prob = dfsProbablity(graph, target, neighbor, visited, time - 1);
                if (prob != 0) {
                    return (double(1) / double(size - 1)) * prob;
                }
            }
        }


        return 0;
    }


    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size()==0) return 1.0;
        unordered_map<int, vector<int>> graph = createGraph(edges);
        vector<bool> visited(n + 1, false);

        return dfsProbablity(graph, target, 1, visited, t);

    }
};
