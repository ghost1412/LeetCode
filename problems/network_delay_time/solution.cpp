class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<array<int, 2>> graph[n+1];
        for(vector<int> it: times){
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int curr = pq.top()[1];
            pq.pop();
            for(array<int, 2> it: graph[curr]){
                int next = it[0];
                int time = it[1];
                if(distance[next] > distance[curr] + time){
                    distance[next] = distance[curr] + time;
                    pq.push({distance[next], next});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<distance.size(); i++) {
            ans = max(ans, distance[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};