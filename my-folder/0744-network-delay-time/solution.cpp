class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (vector<int> it: times) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distances(n+1, INT_MAX);
        distances[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();
            cout<<curr;
            for (pair<int,int> it: graph[curr]) {
                int next = it.first;
                int time = it.second;
                if (distances[next] > distances[curr]+time) {
                    distances[next] = distances[curr]+time;
                    pq.push({distances[next], next});
                }
            }
        }
                
        int ans = 0;
        for(int i = 1; i<distances.size(); i++) {
            ans = max(ans, distances[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
