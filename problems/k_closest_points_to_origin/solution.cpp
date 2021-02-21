class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, vector<int>>> pq;
        int count = 0;
        for(int i=0; i<points.size(); i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];          
            if(count<K){
                pq.push(make_pair(dist, points[i]));
                count++;
            }else{
                auto top = pq.top();
                if(top.first > dist){
                    pq.pop();
                    pq.push(make_pair(dist, points[i]));
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};